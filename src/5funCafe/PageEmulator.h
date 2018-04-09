#pragma once
#include "IPage.h"



class CPageEmulator :
	public CHorizontalLayoutUI,
	public IPage
{
public:
	CPageEmulator();
	~CPageEmulator();

protected:
	virtual void Init();
	virtual void Exit();
	virtual LRESULT OnMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:

};

