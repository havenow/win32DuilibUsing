#include "stdafx.h"
#include "PageWeb.h"


CPageWeb::CPageWeb()
: m_pTab(NULL)
{
}


CPageWeb::~CPageWeb()
{
}

void CPageWeb::Init()
{
	InitControls();
}

void CPageWeb::Exit()
{

}

int CPageWeb::GetSelIndex()
{
	return m_pTab ? m_pTab->GetCurSel() : 0;
}

void CPageWeb::SetSelIndex(int nIndex)
{
	if (m_pTab)
		m_pTab->SelectItem(nIndex);
}
