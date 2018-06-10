// PwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SecureTxt.h"
#include "PwdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPwdDlg dialog


CPwdDlg::CPwdDlg(LPCTSTR lpszTitle, CWnd* pParent /*=NULL*/)
	: m_sTitle(lpszTitle), CDialog(CPwdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPwdDlg)
	m_sPwd = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPwdDlg)
	DDX_Text(pDX, IDC_PWD, m_sPwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPwdDlg, CDialog)
	//{{AFX_MSG_MAP(CPwdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPwdDlg message handlers

CString CPwdDlg::GetPassword() const
{
	return m_sPwd;
}

BOOL CPwdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(CString(_T("SecureTxt - [")) + m_sTitle + _T(']'));
	SetIcon(m_hIcon, TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
