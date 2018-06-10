// SecureTxtView.cpp : implementation of the CSecureTxtView class
//

#include "stdafx.h"
#include "SecureTxt.h"

#include "SecureTxtDoc.h"
#include "SecureTxtView.h"
#include <afxdlgs.h>
#include "PopupMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView

IMPLEMENT_DYNCREATE(CSecureTxtView, CEditView)

BEGIN_MESSAGE_MAP(CSecureTxtView, CEditView)
	//{{AFX_MSG_MAP(CSecureTxtView)
	ON_COMMAND(ID_EDIT_DATETIME, OnEditDatetime)
	ON_COMMAND(ID_OPTIONS_FONT, OnOptionsFont)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_CHAR()
	ON_COMMAND(ID_EDIT_MODUNDO, OnEditModundo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MODUNDO, OnUpdateEditModundo)
	ON_COMMAND(ID_EDIT_MODREDO, OnEditModredo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MODREDO, OnUpdateEditModredo)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView construction/destruction

CSecureTxtView::CSecureTxtView()
{
	// TODO: add construction code here
	m_ur.SetUndoLevels(32);
	m_ur.SetTypingStack(16);
	m_bTyping = 0;
	m_nPrevCursor = 0;
	LoadFont();
}

CSecureTxtView::~CSecureTxtView()
{
	SaveFont();
	m_font.DeleteObject();
}

BOOL CSecureTxtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView drawing

void CSecureTxtView::OnDraw(CDC* pDC)
{
	CSecureTxtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC;
}

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView printing

BOOL CSecureTxtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	
	return CEditView::OnPreparePrinting(pInfo);
}

void CSecureTxtView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSecureTxtView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	pInfo->m_rectDraw.DeflateRect(200, 200);
	CEditView::OnPrint(pDC, pInfo);
}

void CSecureTxtView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView diagnostics

#ifdef _DEBUG
void CSecureTxtView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSecureTxtView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSecureTxtDoc* CSecureTxtView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSecureTxtDoc)));
	return (CSecureTxtDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtView message handlers
void CSecureTxtView::OnReplaceAll( LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase)
{
	GetEditCtrl().SetSel(0, 0);
	CEditView::OnReplaceAll(lpszFind, lpszReplace, bCase);
}

void CSecureTxtView::OnEditDatetime() 
{
	// TODO: Add your command handler code here
	GetEditCtrl().ReplaceSel(CTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S")), TRUE);
}

void CSecureTxtView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetEditCtrl().SetFont(&m_font);
}

void CSecureTxtView::OnOptionsFont() 
{
	// TODO: Add your command handler code here
	LOGFONT lf = { 0 };
	m_font.GetLogFont(&lf);
	CFontDialog dlg(&lf);
	if (dlg.DoModal() == IDOK)
	{
		dlg.GetCurrentFont(&lf);
		m_font.DeleteObject();
		m_font.CreateFontIndirect(&lf);
		GetEditCtrl().SetFont(&m_font);
	}
}

void CSecureTxtView::SaveFont()
{
	LOGFONT lf = { 0 };
	m_font.GetLogFont(&lf);
	CWinApp* pApp = AfxGetApp();
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfCharSet"), lf.lfCharSet);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfClipPrecision"), lf.lfClipPrecision);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfEscapement"), lf.lfEscapement);
	pApp->WriteProfileString(_T("Settings\\Font"), _T("lfFaceName"), lf.lfFaceName);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfHeight"), lf.lfHeight);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfItalic"), lf.lfItalic);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfOrientation"), lf.lfOrientation);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfOutPrecision"), lf.lfOutPrecision);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfPitchAndFamily"), lf.lfPitchAndFamily);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfQuality"), lf.lfQuality);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfStrikeOut"), lf.lfStrikeOut);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfUnderline"), lf.lfUnderline);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfWeight"), lf.lfWeight);
	pApp->WriteProfileInt(_T("Settings\\Font"), _T("lfWidth"), lf.lfWidth);
}

void CSecureTxtView::LoadFont()
{
	LOGFONT lf = { 0 };
	CWinApp* pApp = AfxGetApp();
	lf.lfCharSet = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfCharSet"), DEFAULT_CHARSET);
	lf.lfClipPrecision = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfClipPrecision"), CLIP_DEFAULT_PRECIS);
	lf.lfEscapement = pApp->GetProfileInt(_T("Settings\\Font"), _T("lfEscapement"), 0);
	CString sFaceName = pApp->GetProfileString(_T("Settings\\Font"), _T("lfFaceName"), _T("Arial"));
	_tcsncpy(lf.lfFaceName, sFaceName, LF_FACESIZE - 1);
	lf.lfHeight = pApp->GetProfileInt(_T("Settings\\Font"), _T("lfHeight"), 0);
	lf.lfItalic = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfItalic"), 0);
	lf.lfOrientation = pApp->GetProfileInt(_T("Settings\\Font"), _T("lfOrientation"), 0);
	lf.lfOutPrecision = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfOutPrecision"), OUT_DEFAULT_PRECIS);
	lf.lfPitchAndFamily = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfPitchAndFamily"), DEFAULT_PITCH);
	lf.lfQuality = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfQuality"), DEFAULT_QUALITY);
	lf.lfStrikeOut = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfStrikeOut"), 0);
	lf.lfUnderline = (BYTE)pApp->GetProfileInt(_T("Settings\\Font"), _T("lfUnderline"), 0);
	lf.lfWeight = pApp->GetProfileInt(_T("Settings\\Font"), _T("lfWeight"), FW_NORMAL);
	lf.lfWidth = pApp->GetProfileInt(_T("Settings\\Font"), _T("lfWidth"), 0);
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&lf);
}


void CSecureTxtView::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEditView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	Mark(m_bTyping);
	m_bTyping = FALSE;
	GetDocument()->SetModifiedFlag(TRUE);
}


void CSecureTxtView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_bTyping = TRUE;
	CEditView::OnChar(nChar, nRepCnt, nFlags);
}

void CSecureTxtView::Mark(BOOL bTyping)
{
	CString str;
	GetEditCtrl().GetWindowText(str);
	DWORD dwSel = GetEditCtrl().GetSel();
	int nPrevCursor = m_nPrevCursor;
	m_nPrevCursor = LOWORD(dwSel);
	m_ur.Mark(bTyping, dwSel, str, m_nPrevCursor != nPrevCursor + 1);
}

void CSecureTxtView::OnEditModundo() 
{
	// TODO: Add your command handler code here
	m_ur.DisableMark();	
	DWORD dwSel;
	CString str;
	if (m_ur.Undo(dwSel, str))
	{
		SetWindowText(str);
		GetEditCtrl().SetSel(dwSel);
	}	
	m_ur.EnableMark();
}

void CSecureTxtView::OnUpdateEditModundo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_ur.CanUndo());
}

void CSecureTxtView::OnEditModredo() 
{
	// TODO: Add your command handler code here	
	m_ur.DisableMark();
	DWORD dwSel;
	CString str;
	if (m_ur.Redo(dwSel, str))
	{
		SetWindowText(str);
		GetEditCtrl().SetSel(dwSel);
	}	
	m_ur.EnableMark();
}

void CSecureTxtView::OnUpdateEditModredo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_ur.CanRedo());
}

void CSecureTxtView::ClearUndo()
{
	m_ur.ClearAll();
	Mark(FALSE);
	m_bTyping = FALSE;
	m_nPrevCursor = 0;
}

void CSecureTxtView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	PopupMenu(IDR_MAINFRAME, 1, pWnd, &point);
}
