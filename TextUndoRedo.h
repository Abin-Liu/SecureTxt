// TextUndoRedo.h: interface for the CTextUndoRedo class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __TEXTUNDOREDO_H__
#define __TEXTUNDOREDO_H__

#include <afxtempl.h>

class CTextUndoRedoData
{
public:

	friend class CTextUndoRedo;
	CTextUndoRedoData();
	CTextUndoRedoData(BOOL bTyping, DWORD dwSel, LPCTSTR lpszText, int nStackCount = 0);
	CTextUndoRedoData(const CTextUndoRedoData& rhs);
	const CTextUndoRedoData& operator=(const CTextUndoRedoData& rhs);

private:
	
	int m_nStackCount;
	BOOL m_bTyping;
	DWORD m_dwSel;
	CString m_sText;
};

class CTextUndoRedo  
{
public:	
	
	CTextUndoRedo();
	virtual ~CTextUndoRedo();

	void ClearAll();
	void Mark(BOOL bTyping, DWORD dwSel, LPCTSTR lpszText, BOOL bNoStack = FALSE);	
	void EnableMark();
	void DisableMark();	

	BOOL Undo(DWORD& rSel, CString& rString);
	BOOL Redo(DWORD& rSel, CString& rString);
	
	BOOL CanUndo() const;
	BOOL CanRedo() const;	
	
	void SetUndoLevels(int nLevels);
	int GetUndoLevels() const;

	void SetTypingStack(int nTypingStack);
	int GetTypingStack() const;

private:

	int m_nUndoLevels;
	int m_nTypingStack;
	BOOL m_bLock;
	CList<CTextUndoRedoData, const CTextUndoRedoData&> m_aUndoList;
	CList<CTextUndoRedoData, const CTextUndoRedoData&> m_aRedoList;
};

#endif // __TEXTUNDOREDO_H__
