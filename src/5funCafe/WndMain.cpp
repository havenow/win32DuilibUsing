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