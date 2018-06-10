// SecureTxtView.h : interface of the CSecureTxtView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECURETXTVIEW_H__11D89ED0_9060_469D_A207_D164EA8B033A__INCLUDED_)
#define AFX_SECURETXTVIEW_H__11D89ED0_9060_469D_A207_D164EA8B033A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TextUndoRedo.h"


class CSecureTxtView : public CEditView
{
protected: // create from serialization only
	CSecureTxtView();
	DECLARE_DYNCREATE(CSecureTxtView)

// Attributes
public:
	CSecureTxtDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSecureTxtView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnReplaceAll( LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	void ClearUndo();
	virtual ~CSecureTxtView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	void Mark(BOOL bTyping);
	CTextUndoRedo m_ur;
	CFont m_font;
	BOOL m_bTyping;
	int m_nPrevCursor;

// Generated message map functions
protected:	
	void LoadFont();
	void SaveFont();
	//{{AFX_MSG(CSecureTxtView)
	afx_msg void OnEditDatetime();
	afx_msg void OnOptionsFont();
	afx_msg void OnChange();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEditModundo();
	afx_msg void OnUpdateEditModundo(CCmdUI* pCmdUI);
	afx_msg void OnEditModredo();
	afx_msg void OnUpdateEditModredo(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SecureTxtView.cpp
inline CSecureTxtDoc* CSecureTxtView::GetDocument()
   { return (CSecureTxtDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECURETXTVIEW_H__11D89ED0_9060_469D_A207_D164EA8B033A__INCLUDED_)
