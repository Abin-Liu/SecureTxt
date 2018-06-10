// SecureTxt.h : main header file for the SECURETXT application
//

#if !defined(AFX_SECURETXT_H__BB3186B0_B802_4F3D_B128_65E6C0172CC6__INCLUDED_)
#define AFX_SECURETXT_H__BB3186B0_B802_4F3D_B128_65E6C0172CC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSecureTxtApp:
// See SecureTxt.cpp for the implementation of this class
//

class CSecureTxtApp : public CWinApp
{
public:
	CSecureTxtApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSecureTxtApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSecureTxtApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECURETXT_H__BB3186B0_B802_4F3D_B128_65E6C0172CC6__INCLUDED_)
