#include "stdafx.h"
#include "WndMain.h"


CWndMain::CWndMain()
{
}


CWndMain::~CWndMain()
{
}


LPCWSTR CWndMain::GetWndName() const
{
	return MAIN_WND_NAME;
}

LPCWSTR CWndMain::GetXmlPath() const
{
	static LPCWSTR lpName = L"WndMain.xml";
	return lpName;
}
