#include "stdafx.h"
#include "WndMain.h"



bool CWndMain::OnNotifyBtnClose(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{
		Exit();
	}
	return true;
}

bool CWndMain::OnNotifyBtnMin(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{

	}
	return true;
}

bool CWndMain::OnNotifyBtnMax(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{

	}
	return true;
}

bool CWndMain::OnNotifyBtnRestore(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{

	}
	return true;
}
