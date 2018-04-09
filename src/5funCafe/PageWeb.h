#pragma once
#include "IPage.h"



class CPageWeb :
	public CHorizontalLayoutUI,
	public IPage
{
public:
	CPageWeb();
	~CPageWeb();

protected:
	virtual void Init();
	virtual void Exit();
	virtual int GetSelIndex();
	virtual void SetSelIndex(int nIndex);

	BEGIN_INIT_CTRL()
		DECLARE_CTRL_TYPE_PAGE(m_pTab, CTabLayoutUI, L"tab_web")
	END_INIT_CTRL()

private:
	CTabLayoutUI *m_pTab;

};

