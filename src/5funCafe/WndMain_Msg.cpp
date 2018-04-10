#include "stdafx.h"
#include "WndMain.h"
#include "main.h"


LRESULT CWndMain::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lResule = 0;
	if (ProcessMsg(uMsg, wParam, lParam, lResule))
	{
		if (m_bExit)
			return 0;
		if (uMsg > WM_MAINWND_MSG_TASK_BEGIN&&uMsg < WM_MAINWND_MSG_TASK_END)
		{

		}
		else if (uMsg > WM_MAINWND_MSG_PAGE_ROOM_BEGIN && uMsg < WM_MAINWND_MSG_PAGE_ROOM_END)
		{//房间页面消息，扔给页面内部去处理
			if (m_pPageRoom)
				m_pPageRoom->OnMsg(uMsg, wParam, lParam);
		}
		else if (uMsg > WM_MAINWND_MSG_PAGE_EMULATOR_BEGIN && uMsg < WM_MAINWND_MSG_PAGE_EMULATOR_END)
		{//模拟器页面消息，扔给页面内部去处理
			if (m_pPageEmulator)
				m_pPageEmulator->OnMsg(uMsg, wParam, lParam);
		}
		return lResule;
	}
	//switch (uMsg)
	//{
	//case WM_SIZE:
	//{

	//}
	//break;
	//case WM_TIMER:
	//{

	//}
	//break;
	//}
	return CWndBase::HandleMessage(uMsg, wParam, lParam);
}

LRESULT CWndMain::OnMsgCopyData(WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	bHandled = TRUE;
	return 0;
}

LRESULT CWndMain::OnMsgSize(WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	if (g_emuRenderHwnd)
		::PostMessage(g_emuRenderHwnd, WM_SIZE, 0, 0);
	bHandled = TRUE;
	return 0;
}

LRESULT CWndMain::OnMsgTimer(WPARAM wParam, LPARAM lParam, BOOL &bHandled)
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
