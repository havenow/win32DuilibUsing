#include "stdafx.h"
#include "PageEmulator.h"


CPageEmulator::CPageEmulator()
	: m_pTabKey(nullptr)
{
}


CPageEmulator::~CPageEmulator()
{
}

void CPageEmulator::Init()
{
	InitControls();
	BindControls();
}

void CPageEmulator::Exit()
{

}

LRESULT CPageEmulator::OnMsg(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

bool CPageEmulator::OnNotifyOptBasicKey(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_SELECTCHANGED)
	{
		m_pTabKey->SelectItem(0);
	}
	return true;
}

bool CPageEmulator::OnNotifyOptComposeKey(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_SELECTCHANGED)
	{
		m_pTabKey->SelectItem(1);
	}
	return true;
}

bool CPageEmulator::OnNotifyBtnCoin(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{

	}
	return true;
}

bool CPageEmulator::OnNotifyBtnStart(void* lpParam)
{
	TNotifyUI* pNotify = (TNotifyUI*)lpParam;
	if (pNotify->sType == DUI_MSGTYPE_CLICK)
	{

	}
	return true;
}