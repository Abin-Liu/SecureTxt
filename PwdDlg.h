#if !defined(AFX_PWDDLG_H__A3D5A612_436B_46F6_BEB1_EF34265C62EB__INCLUDED_)
#define AFX_PWDDLG_H__A3D5A612_436B_46F6_BEB1_EF34265C62EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PwdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPwdDlg dialog

class CPwdDlg : public CDialog
{
// Construction
public:
	CString GetPassword() const;
	CPwdDlg(LPCTSTR lpszTitle, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPwdDlg)
	enum { IDD = IDD_PWDDLG };
	CString	m_sPwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPwdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPwdDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	HICON m_hIcon;
	CString m_sTitle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PWDDLG_H__A3D5A612_436B_46F6_BEB1_EF34265C62EB__INCLUDED_)
