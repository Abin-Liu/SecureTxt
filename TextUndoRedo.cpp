// TextUndoRedo.cpp: implementation of the CTextUndoRedo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TextUndoRedo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CTextUndoRedoData::CTextUndoRedoData():
 m_bTyping(FALSE), m_dwSel(0), m_nStackCount(0)
{
}

CTextUndoRedoData::CTextUndoRedoData(BOOL bTyping, DWORD dwSel, LPCTSTR lpszText, int nStackCount):
 m_bTyping(bTyping), m_dwSel(dwSel), m_sText(lpszText), m_nStackCount(nStackCount)
{
}

CTextUndoRedoData::CTextUndoRedoData(const CTextUndoRedoData& rhs)
{
	m_bTyping = rhs.m_bTyping;
	m_dwSel = rhs.m_dwSel;
	m_sText = rhs.m_sText;
	m_nStackCount = rhs.m_nStackCount;
}

const CTextUndoRedoData& CTextUndoRedoData::operator=(const CTextUndoRedoData& rhs)
{
	m_bTyping = rhs.m_bTyping;
	m_dwSel = rhs.m_dwSel;
	m_sText = rhs.m_sText;
	m_nStackCount = rhs.m_nStackCount;
	return *this;
}

CTextUndoRedo::CTextUndoRedo()
{
	m_bLock = FALSE;
	m_nTypingStack = 16;
	m_nUndoLevels = 10;
}

CTextUndoRedo::~CTextUndoRedo()
{

}

void CTextUndoRedo::Mark(BOOL bTyping, DWORD dwSel, LPCTSTR lpszText, BOOL bNoStack)
{
	if (!m_bLock)
	{
		m_aRedoList.RemoveAll();
		BOOL bAdd = TRUE;
		if (!bNoStack && bTyping && m_aUndoList.GetCount())
		{
			CTextUndoRedoData& data = m_aUndoList.GetHead();
			if (data.m_bTyping && data.m_nStackCount + 1 < m_nTypingStack)
			{
				data.m_dwSel = dwSel;
				data.m_sText = lpszText;
				data.m_nStackCount++;
				bAdd = FALSE;
			}
		}
		
		if (bAdd)
			m_aUndoList.AddHead(CTextUndoRedoData(bTyping, dwSel, lpszText));
		
		if (m_aUndoList.GetCount() > m_nUndoLevels + 1)
			m_aUndoList.RemoveTail();
	}		
}

BOOL CTextUndoRedo::Undo(DWORD& rSel, CString& rString)
{
	if (!CanUndo())
		return FALSE;

	m_aRedoList.AddHead(m_aUndoList.RemoveHead());
	CTextUndoRedoData& data = m_aUndoList.GetHead();
	rSel = data.m_dwSel;
	rString = data.m_sText;
	return TRUE;
}

BOOL CTextUndoRedo::Redo(DWORD& rSel, CString& rString)
{
	if (!CanRedo())
		return FALSE;
	
	CTextUndoRedoData data = m_aRedoList.RemoveHead();
	m_aUndoList.AddHead(data);
	rSel = data.m_dwSel;
	rString = data.m_sText;
	return TRUE;
}

BOOL CTextUndoRedo::CanUndo() const
{
	return m_aUndoList.GetCount() > 1;
}

BOOL CTextUndoRedo::CanRedo() const
{
	return m_aRedoList.GetCount();
}

void CTextUndoRedo::ClearAll()
{
	m_aUndoList.RemoveAll();
	m_aRedoList.RemoveAll();
	m_bLock = FALSE;
}

void CTextUndoRedo::EnableMark()
{
	m_bLock = FALSE;
}

void CTextUndoRedo::DisableMark()
{
	m_bLock = TRUE;
}

void CTextUndoRedo::SetUndoLevels(int nLevels)
{
	m_nUndoLevels = nLevels;
	while (m_aUndoList.GetCount() > m_nUndoLevels + 1)
		m_aUndoList.RemoveTail();
}

int CTextUndoRedo::GetUndoLevels() const
{
	return m_nUndoLevels;
}

int CTextUndoRedo::GetTypingStack() const
{
	return m_nTypingStack;
}

void CTextUndoRedo::SetTypingStack(int nTypingStack)
{
	m_nTypingStack = max(1, nTypingStack);
}
