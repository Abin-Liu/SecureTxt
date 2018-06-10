// SecureTxtDoc.h : interface of the CSecureTxtDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECURETXTDOC_H__EDDEBC54_3DF7_42E3_909C_011236212480__INCLUDED_)
#define AFX_SECURETXTDOC_H__EDDEBC54_3DF7_42E3_909C_011236212480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SecureTxtCrypto.h"

class CSecureTxtDoc : public CDocument
{
protected: // create from serialization only
	CSecureTxtDoc();
	DECLARE_DYNCREATE(CSecureTxtDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSecureTxtDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateFrameTitle();
	void SetModifiedFlag(BOOL bModified = TRUE);
	virtual ~CSecureTxtDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	CSecureTxtCrypto m_crypto;	

// Generated message map functions
protected:
	void ErrorMessage(LPCTSTR lpszFmt, LPCTSTR lpszParam);
	BOOL RequestPassword(LPCTSTR lpszTitle, BOOL bIsNew = FALSE);

	//{{AFX_MSG(CSecureTxtDoc)
	afx_msg void OnOptionsPassword();
	afx_msg void OnUpdateOptionsPassword(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECURETXTDOC_H__EDDEBC54_3DF7_42E3_909C_011236212480__INCLUDED_)
