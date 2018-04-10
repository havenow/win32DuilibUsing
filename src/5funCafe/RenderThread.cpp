#include "RenderThread.h"
#include "main.h"
#include "GlobalData.h"

#include <WindowsX.h>

#define UI_TEXT		L"EmuVideoWindowClass"

LRESULT CALLBACK CRenderThread::wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CRenderThread* pRenderThread = (CRenderThread*)::GetProp(hWnd, UI_TEXT);
	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
	{
		printf("WM_CLOSE\n");
		::PostQuitMessage(0);
	}
	break;
	case WM_CHAR:
	{
		switch ((int)wParam)
		{
		case VK_F12:
		{
			printf("VK_F12\n");
		}
		break;
		}
	}
	break;
	case WM_SIZE:
	{
		if (pRenderThread && pRenderThread->GetWnd() == hWnd)
		{
			g_glesRender.setWH(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			RECT rect;
			GetWindowRect(pRenderThread->GetMainWnd(), &rect);
			MoveWindow(pRenderThread->GetWnd(), 40, 120, rect.right - rect.left - 600, rect.bottom - rect.top - 350, TRUE);
		}
	}
	break;
	default:
		return  DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return  0;
}

ATOM CRenderThread::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_DBLCLKS;//CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = wndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;//LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WKEDEMO));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCE(IDC_HOOKDEMO);
	wcex.lpszClassName = UI_TEXT;
	wcex.hIconSm = NULL;
	return RegisterClassEx(&wcex);
}

BOOL CRenderThread::InitInstance(HINSTANCE hInstance)
{
	HWND hWnd;
	hWnd = CreateWindow(UI_TEXT, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hMainWnd, NULL, hInstance, NULL);
	DWORD tmep = GetLastError();
	if (!hWnd)
		return FALSE;
	m_hWnd = hWnd;
	::SetProp(m_hWnd, UI_TEXT, (HANDLE)this);
	return TRUE;
}

void CRenderThread::Show(const bool bShow/*=true*/)
{
	UINT uMode = bShow ? SW_SHOW : SW_HIDE;
	ShowWindow(m_hWnd, uMode);
	if (bShow)
		UpdateWindow(m_hWnd);
	MoveWindow(m_hWnd, 40, 120, 800, 600, TRUE);
}

bool CRenderThread::Create(HINSTANCE hInst, HWND hParent)
{
	MyRegisterClass(hInst);
	DWORD tmep = GetLastError();
	m_hMainWnd = hParent;
	InitInstance(hInst);

	g_emuRenderHwnd = m_hWnd;

	return true;
}

CRenderThread::CRenderThread(void)
{

}


CRenderThread::~CRenderThread(void)
{

}

bool CRenderThread::InitGLES()
{
	g_glesRender.setHwnd(g_emuRenderHwnd);
	g_glesRender.initOpenGLES20();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_DEPTH_TEST);
	g_glesRender.initShader();
	g_glesRender.initVideoTexture();
	char strTipsImg[512];
	sprintf_s(strTipsImg, "%sloading\\tips_fullscreen.png", CGlobalData::Instance()->GetExePath().c_str());
	g_glesRender.initTipsBuffer(strTipsImg);
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(strTipsImg, "%sloading\\countdown%d.png", CGlobalData::Instance()->GetExePath().c_str(), i);
		g_glesRender.initCountDownBuffer(strTipsImg, i);
	}
	LoadingBuffer* pLoadBuffer = CGlobalData::Instance()->GetLoadBuffer(0);
	g_glesRender.loopVideo(pLoadBuffer->nWidth, pLoadBuffer->nHeight, (BYTE *)pLoadBuffer->pData);

	return 0;
}

bool CRenderThread::InvolkEmu()
{
	/*CGlobal::Instance()->SetCoreloopState(Loop_State_Emu_Start);
	EmuManager::Instance()->setJson(CGlobal::Instance()->GetJson4Emu().c_str());
	string strStatePath = GetDocumentPath(CGlobal::Instance()->GetGameType_str().c_str(), CGlobal::Instance()->GetRomNameNoExt().c_str());
	EmuManager::Instance()->getEmuConfig()->setConfig(STATE_PATH, strStatePath);
	EmuManager::Instance()->getEmuConfig()->setConfig(ROM_NAME, CGlobal::Instance()->GetRomNameNoExt().c_str());
	EmuManager::Instance()->getEmuConfig()->setConfig(SCREEN_SHOT_PATH, GetDocumentPath("img"));

	EmuManager::Instance()->InitConfig();
	EmuManager::Instance()->setExePath(g_strExeDir);

	EmuManager::Instance()->Init();
	cocos_emu_setAudioCallBack(audioCreate, audioPlay, audioStart, audioPause);
	cocos_emu_setHwnd4Sound(g_hwnd);

	EmuManager::Instance()->setEmuInvoke(true);*/
	return true;
}

bool CRenderThread::start()
{
	return Thread::start();
}

void CRenderThread::join()
{
	//audioStop();
	g_glesRender.destroyOpenGLES20();
	/*EmuManager::Instance()->ExitEmu();
	EmuManager::Instance()->delEngineFactory();*/
	Thread::join();
}

bool CRenderThread::run()
{
	Create(m_hInstance, m_hMainWnd);
	Show(true);
	InitGLES();
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, m_hWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (IsIconic(m_hMainWnd))
				continue;
			if (1/*nScale == UNIFORM_SCALE*/)
				g_glesRender.render(true);
			else
				g_glesRender.render(false);

			g_glesRender.swapBuffer();
		}
	}

	return true;
}
