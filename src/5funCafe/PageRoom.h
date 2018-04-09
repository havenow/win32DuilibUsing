#pragma once
#include "IPage.h"


class CPageRoom :
	public CHorizontalLayoutUI,
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

