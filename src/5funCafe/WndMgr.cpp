#include "StdAfx.h"
#include "WndMgr.h"


CWndMgr::CWndMgr()
: m_hDownloadWnd(NULL)
{
}


CWndMgr::~CWndMgr()
{
}

void CWndMgr::AddWnd(HWND hWnd, CWndBase* pWnd)
{
	m_wndMap[hWnd] = pWnd;
}

void CWndMgr::RemoveWnd(HWND hWnd)
{
	auto itor = m_wndMap.find(hWnd);
	if (itor != m_wndMap.end())
		m_wndMap.erase(itor);
}

CWndBase* CWndMgr::GetWndObject(HWND hWnd)
{
	auto itor = m_wndMap.find(hWnd);
	if (itor == m_wndMap.end())
		return NULL;
	if (!IsWindow(hWnd))
	{
		m_wndMap.erase(itor);
		return NULL;
	}
	return itor->second;
}

void CWndMgr::CloseAll()
{
	for (auto itor = m_wndMap.begin(); itor != m_wndMap.end(); ++itor)
	{
		HWND hWnd = itor->first;
		if (IsWindow(hWnd))
			::PostMessage(hWnd, WM_CLOSE, 0, 0);
	}
	m_wndMap.clear();
}

void CWndMgr::ShowAll(bool bShow)
{
	for (auto itor = m_wndMap.begin(); itor != m_wndMap.end(); ++itor)
	{
		HWND hWnd = itor->first;
		if (hWnd != m_hDownloadWnd && IsWindow(hWnd))
			::ShowWindow(hWnd, bShow ? SW_SHOW : SW_HIDE);
	}
}

