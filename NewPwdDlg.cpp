// NewPwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SecureTxt.h"
#include "NewPwdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg dialog


CNewPwdDlg::CNewPwdDlg(LPCTSTR lpszTitle, CWnd* pParent /*=NULL*/)
	: m_sTitle(lpszTitle), CDialog(CNewPwdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewPwdDlg)
	m_sPwd1 = _T("");
	m_sPwd2 = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CNewPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewPwdDlg)
	DDX_Control(pDX, IDC_PWD2, m_wndPwd2);
	DDX_Text(pDX, IDC_PWD1, m_sPwd1);
	DDX_Text(pDX, IDC_PWD2, m_sPwd2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewPwdDlg, CDialog)
	//{{AFX_MSG_MAP(CNewPwdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg message handlers

void CNewPwdDlg::OnOK()
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_sPwd1.CompareNoCase(m_sPwd2))
	{
		MessageBox(_T("两次输入的密码不一致，请重新输入！"), _T("无效输入"), MB_ICONEXCLAMATION);
		m_wndPwd2.SetFocus();
		m_wndPwd2.SetSel(0, -1);
		return;
	}

	EndDialog(IDOK);
}

CString CNewPwdDlg::GetPassword() const
{
	return m_sPwd1;
}

BOOL CNewPwdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(CString(_T("SecureTxt - [")) + m_sTitle + _T(']'));
	SetIcon(m_hIcon, TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
