#pragma once
#include "IPage.h"


class CPageRoom :
	public CVerticalLayoutUI,
	public IPage
{
public:
	CPageRoom();
	~CPageRoom();

protected:
	virtual void Init();
	virtual void Exit();
	virtual LRESULT OnMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);


private:

};

