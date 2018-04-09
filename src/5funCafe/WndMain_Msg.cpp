#include "stdafx.h"
#include "WndMain.h"



LRESULT CWndMain::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lResule = 0;
	if (ProcessMsg(uMsg, wParam, lParam, lResule))
		return lResule;
	return CWndBase::HandleMessage(uMsg, wParam, lParam);
}

LRESULT CWndMain::OnMsgCopyData(WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	bHandled = TRUE;
	return 0;
}

LRESULT CWndMain::OnMsgGameHall(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CWndMain::OnMsgPageRoom(WPARAM wParam, LPARAM lParam)
{
	return 0;
}
