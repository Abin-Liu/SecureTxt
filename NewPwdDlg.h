#if !defined(AFX_NEWPWDDLG_H__07D5EAA7_9A13_4DA4_B57B_73D569F4C9D1__INCLUDED_)
#define AFX_NEWPWDDLG_H__07D5EAA7_9A13_4DA4_B57B_73D569F4C9D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewPwdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg dialog

class CNewPwdDlg : public CDialog
{
// Construction
public:
	CString GetPassword() const;
	CNewPwdDlg(LPCTSTR lpszTitle, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewPwdDlg)
	enum { IDD = IDD_NEWPWDDLG };
	CEdit	m_wndPwd2;
	CString	m_sPwd1;
	CString	m_sPwd2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewPwdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewPwdDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	HICON m_hIcon;
	CString m_sTitle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWPWDDLG_H__07D5EAA7_9A13_4DA4_B57B_73D569F4C9D1__INCLUDED_)
