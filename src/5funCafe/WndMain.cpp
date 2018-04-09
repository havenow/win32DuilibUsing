#include "stdafx.h"
#include "WndMain.h"


CWndMain::CWndMain()
	: m_pPageRoom(NULL)
	, m_pPageWeb(NULL)
{
	m_dwStyle = UI_WNDSTYLE_FRAME;
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

void CWndMain::InitWindow()
{
	CWndBase::InitWindow();
}

void CWndMain::OnFinalMessage(HWND hWnd)
{
	CWndBase::OnFinalMessage(hWnd);
	//�����ã��ᵼ����Ϣѭ�����رգ������޷���ȫ�ر�
	::PostQuitMessage(0);//CefQuitMessageLoop();
}

void CWndMain::Exit()
{
	if (m_pPageWeb)
		m_pPageWeb->Exit();
	if (m_pPageRoom)
		m_pPageRoom->Exit();
	Close();
}