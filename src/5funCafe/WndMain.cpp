#include "stdafx.h"
#include "WndMain.h"
#include "PageWeb.h"
#include "PageRoom.h"
#include "PageEmulator.h"
#include "main.h"

CWndMain::CWndMain()
	: m_pPageRoom(NULL)
	, m_pPageWeb(NULL)
	, m_pPageEmulator(NULL)
	, m_bExit(false)
	, m_pWebTable(NULL)
{
	m_dwStyle = UI_WNDSTYLE_FRAME;
}


CWndMain::~CWndMain()
{
}

CControlUI* CWndMain::CreateControl(LPCTSTR pstrClass)
{
	if (wcscmp(pstrClass, L"PageWebRoot") == 0)
	{
		CPageWeb* p = new CPageWeb;
		m_pPageWeb = p;
		return p;
	}
	if (wcscmp(pstrClass, L"PageRoomRoot") == 0)
	{
		CPageRoom* p = new CPageRoom;
		m_pPageRoom = p;
		return p;
	}
	if (wcscmp(pstrClass, L"PageEmulaotrRoot") == 0)
	{
		CPageEmulator* p = new CPageEmulator;
		m_pPageEmulator = p;
		return p;
	}
	if (wcscmp(pstrClass, L"CefWebUI") == 0)
		return new CCefWebkitUI;

	CDialogBuilder dlgBuilder;
	if (wcscmp(pstrClass, L"PageWeb") == 0)
		return dlgBuilder.Create(L"PageWeb.xml", (UINT)0, this, &m_pm);
	if (wcscmp(pstrClass, L"PageRoom") == 0)
		return dlgBuilder.Create(L"PageRoom.xml", (UINT)0, this, &m_pm);
	if (wcscmp(pstrClass, L"PageEmulator") == 0)
		return dlgBuilder.Create(L"PageEmulator.xml", (UINT)0, this, &m_pm);
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

void CWndMain::InitWindow()
{
	CWndBase::InitWindow();
	m_pLblGameName->SetText(L"拳皇97");
	g_renderThread.SetMainWnd(m_hWnd);
	g_renderThread.start();
	g_renderThread.InvolkEmu();

	wstring strUrl = m_pWebTable->GetLoadingUrl();
	if (strUrl.empty())
	{
		m_pWebTable->Navigate(L"http://netbattle-cloud.5fun.com/cloud/role.html");
	}
}

void CWndMain::OnFinalMessage(HWND hWnd)
{
	CWndBase::OnFinalMessage(hWnd);
	//不调用，会导致消息循环不关闭，程序无法完全关闭
	CefQuitMessageLoop(); //::PostQuitMessage(0);//CefQuitMessageLoop();
}

void CWndMain::Exit()
{
	if (m_pWebTable)
		m_pWebTable->Close();
	::SendMessage(g_emuRenderHwnd, WM_CLOSE, 0, 0);
	g_renderThread.join();
	m_bExit = true;
	if (m_pPageWeb)
		m_pPageWeb->Exit();
	if (m_pPageRoom)
		m_pPageRoom->Exit();
	Close();
}