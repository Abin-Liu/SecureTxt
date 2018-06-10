// SecureTxtDoc.cpp : implementation of the CSecureTxtDoc class
//

#include "stdafx.h"
#include "SecureTxt.h"

#include "SecureTxtDoc.h"
#include "PwdDlg.h"
#include "NewPwdDlg.h"
#include "SecureTxtView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const GUID SECURETXT_ID = { /* CD15CF9C-9E46-413D-8495-F8E91AEE18A3 */
	0xCD15CF9C,
	0x9E46,
	0x413D,
	{0x84, 0x95, 0xF8, 0xE9, 0x1A, 0xEE, 0x18, 0xA3}
};

const GUID SECURETXT_SAMPLE = { /* CEFA304D-7908-4870-917B-1A8B844AF8EB */
	0xCEFA304D,
	0x7908,
	0x4870,
	{0x91, 0x7B, 0x1A, 0x8B, 0x84, 0x4A, 0xF8, 0xEB}
};

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtDoc

IMPLEMENT_DYNCREATE(CSecureTxtDoc, CDocument)

BEGIN_MESSAGE_MAP(CSecureTxtDoc, CDocument)
	//{{AFX_MSG_MAP(CSecureTxtDoc)
	ON_COMMAND(ID_OPTIONS_PASSWORD, OnOptionsPassword)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_PASSWORD, OnUpdateOptionsPassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtDoc construction/destruction

CSecureTxtDoc::CSecureTxtDoc()
{
	// TODO: add one-time construction code here	
}

CSecureTxtDoc::~CSecureTxtDoc()
{
}

BOOL CSecureTxtDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_crypto.DeletePassword();
	((CSecureTxtView*)m_viewList.GetHead())->ClearUndo();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtDoc diagnostics

#ifdef _DEBUG
void CSecureTxtDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSecureTxtDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtDoc commands

BOOL CSecureTxtDoc::RequestPassword(LPCTSTR lpszTitle, BOOL bIsNew)
{
	CString sTitle(lpszTitle);
	int nSlash = sTitle.ReverseFind(_T('\\'));
	if (nSlash != -1)
		sTitle = sTitle.Mid(nSlash + 1);

	CString sPassword;
	if (bIsNew)
	{
		CNewPwdDlg dlg(sTitle);
		if (dlg.DoModal() != IDOK)
			return FALSE;
		sPassword = dlg.m_sPwd1;
	}
	else
	{
		CPwdDlg dlg(sTitle);
		if (dlg.DoModal() != IDOK)
			return FALSE;
		sPassword = dlg.m_sPwd;
	}

	m_crypto.SetPassword(sPassword, TRUE);
	return TRUE;
}

void CSecureTxtDoc::OnOptionsPassword() 
{
	// TODO: Add your command handler code here
	CString sPwd;
	if (RequestPassword(GetTitle(), TRUE))
		SetModifiedFlag(TRUE);
}

void CSecureTxtDoc::OnUpdateOptionsPassword(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
 	if (m_crypto.HasPassword())
		pCmdUI->SetText(_T("更改密码(&C)..."));
	else
		pCmdUI->SetText(_T("创建密码(&C)..."));
}

BOOL CSecureTxtDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized creation code here
	CFile file;
	if (!file.Open(lpszPathName, CFile::modeRead))
	{
		ErrorMessage(_T("无法打开文件:\n%s"), lpszPathName);
		return FALSE;
	}

	CString sContents;
	DWORD dwFileLen = file.GetLength();
	if (dwFileLen == 0)
	{
		m_crypto.DeletePassword();
	}
	else
	{
		if (dwFileLen < sizeof(GUID) * 2)
		{
			ErrorMessage(_T("此文件不是合法的SecureTxt数据格式:\n%s"), lpszPathName);
			return FALSE;
		}	

		GUID guid;
		file.Read(&guid, sizeof(GUID));		
		if (::memcmp(&guid, &SECURETXT_ID, sizeof(GUID)))
		{
			ErrorMessage(_T("此文件不是合法的SecureTxt数据格式:\n%s"), lpszPathName);
			return FALSE;
		}

		if (!RequestPassword(lpszPathName))
			return FALSE;

		file.Read(&guid, sizeof(GUID));
		m_crypto.Decrypt((LPBYTE)&guid, sizeof(GUID));
		if (::memcmp(&guid, &SECURETXT_SAMPLE, sizeof(GUID)))
		{
			m_crypto.RestoreLastPassword();
			AfxMessageBox(_T("密码错误，或文件已损坏。"), MB_ICONEXCLAMATION);
			return FALSE;
		}
				
		dwFileLen -= sizeof(GUID) * 2;
		LPTSTR p = sContents.GetBuffer(dwFileLen / sizeof(TCHAR));
		file.Read(p, dwFileLen);
		m_crypto.Decrypt((LPBYTE)p, dwFileLen);
		sContents.ReleaseBuffer(dwFileLen / sizeof(TCHAR));			
	}	

	((CEditView*)m_viewList.GetHead())->SetWindowText(sContents);
	SetModifiedFlag(FALSE);
	((CSecureTxtView*)m_viewList.GetHead())->ClearUndo();
	return TRUE;
}

BOOL CSecureTxtDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFile file;
	if (!file.Open(lpszPathName, CFile::modeWrite | CFile::modeCreate))
	{
		ErrorMessage(_T("无法写入文件:\n%s"), lpszPathName);
		return FALSE;
	}

	if (!m_crypto.HasPassword() && !RequestPassword(lpszPathName, TRUE))
		return FALSE;

	file.Write(&SECURETXT_ID, sizeof(GUID));
	GUID sample;
	::memcpy(&sample, &SECURETXT_SAMPLE, sizeof(GUID));
	m_crypto.Encrypt((LPBYTE)&sample, sizeof(GUID));
	file.Write(&sample, sizeof(GUID));

	CString sContents;
	((CEditView*)m_viewList.GetHead())->GetWindowText(sContents);
	LPTSTR psz = sContents.GetBuffer(sContents.GetLength());
	m_crypto.Encrypt((LPBYTE)psz, sContents.GetLength() * sizeof(TCHAR));		
	file.Write(psz, sContents.GetLength() * sizeof(TCHAR));
	SetModifiedFlag(FALSE);
	return TRUE;
}

void CSecureTxtDoc::ErrorMessage(LPCTSTR lpszFmt, LPCTSTR lpszParam)
{
	CString sErr;
	sErr.Format(lpszFmt, lpszParam);
	AfxMessageBox(sErr, MB_ICONEXCLAMATION);
}

void CSecureTxtDoc::SetModifiedFlag(BOOL bModified)
{
	CDocument::SetModifiedFlag(bModified);
	UpdateFrameTitle();
}

void CSecureTxtDoc::SetTitle(LPCTSTR lpszTitle) 
{
	// TODO: Add your specialized code here and/or call the base class	
	CDocument::SetTitle(lpszTitle);
	UpdateFrameTitle();
}

void CSecureTxtDoc::UpdateFrameTitle()
{
	CFrameWnd *pFrame = ((CEditView*)m_viewList.GetHead())->GetParentFrame();
	if (pFrame && pFrame->GetSafeHwnd())
	{
		CString sDoc = GetTitle();
		CString sTitle;
		sTitle.Format(_T("SecureTxt - [%s%s]"), (LPCTSTR)sDoc, IsModified() ? _T(" *") : _T(""));
		pFrame->SetWindowText(sTitle);
	}
}