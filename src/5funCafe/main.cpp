// 5funCafe.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "5funCafe.h"
#include "WndMain.h"
#include "main.h"
#include "GlobalData.h"
#include "CefBase/util.h"
#include "CefBase/client_app_browser.h"
#include "CefBase/main_message_loop_std.h"
CglesRender		g_glesRender;
CRenderThread	g_renderThread;
HWND			g_emuRenderHwnd = nullptr;

bool InitLog();
bool CheckInstance(HANDLE& hMutex);
bool InitDuilibRes(HINSTANCE hInstance);//初始化界面库资源
bool InitModules(HINSTANCE hInstance);//初始化其他模块
void ExitModules();
void InitLoadBuffer();
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	HANDLE hMutex = NULL;
	if (CheckInstance(hMutex))
	{
		OutputDebugString(L"已经有一个实例正在运行，退出\n");
		return 0;
	}
	PublicLib::EnableDebugPrivilege();
	InitLog();
	CoInitialize(NULL);
	CefMainArgs main_args(hInstance);
	CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
	command_line->InitFromString(::GetCommandLineW());
	CefRefPtr<CefApp> app(new ClientAppBrowser());
	void* sandbox_info = NULL;
	CefSettings settings;
	std::string locale("zh-CN");
	cef_string_utf8_to_utf16(locale.c_str(), locale.size(), &settings.locale);
	settings.no_sandbox = 1;
	settings.background_color = 0x1C1C1C;
	wstring strAppDataPath = GetAppDataPath();
	wstring strCachePath = strAppDataPath + L"CefCache";
	SHCreateDirectory(NULL, strCachePath.c_str());
	cef_string_set(strCachePath.c_str(), strCachePath.size(), &settings.cache_path, 1);
	wstring strRunPath = GetRunPathW();
	cef_string_set(strRunPath.c_str(), strRunPath.size(), &settings.locales_dir_path, 1);
	//wstring strRender = strRunPath + EXE_RENDER;
	//cef_string_set(strRender.c_str(), strRender.size(), &settings.browser_subprocess_path, 1);
#ifdef _DEBUG
	wstring strLogPath = strAppDataPath + L"CefLog.log";
	if (PathFileExists(strLogPath.c_str()))
	{
		DeleteFile(strLogPath.c_str());
	}
	cef_string_set(strLogPath.c_str(), strLogPath.size(), &settings.log_file, 1);
#else
	settings.log_severity = LOGSEVERITY_DISABLE;
#endif
	settings.multi_threaded_message_loop = 0;
	settings.single_process = 1;
	settings.persist_session_cookies = 1;
	scoped_ptr<MainMessageLoop> message_loop(new MainMessageLoopStd);
	g_renderThread.SetInstance(hInstance);
	if (!InitDuilibRes(hInstance))
	{
		MessageBox(NULL, L"初始化界面库资源失败！", L"出错了：", MB_OK | MB_ICONERROR);
		CloseHandle(hMutex);
		return 0;
	}
	CefInitialize(main_args, settings, app, sandbox_info);
	InitLoadBuffer();
	InitModules(hInstance);
	CWndMain* pWnd = new CWndMain;
	g_emuRenderHwnd = pWnd->Create(NULL);
	pWnd->CenterWindow();
	bool bShow = wcscmp(lpCmdLine, L"/bootrun") != 0;
	pWnd->ShowWindow(bShow, bShow);
	message_loop->Run(); //CPaintManagerUI::MessageLoop();//message_loop->Run();
	ExitModules();
	CefShutdown();
	message_loop.reset();
	CPaintManagerUI::Term();
	CloseHandle(hMutex);
	CoUninitialize();
	return 0;
}


bool InitLog()
{
	//初始化XYClient日志
	wstring strLogPath = GetDocumentPath() + L"\\log\\5funCafe";
	SHCreateDirectory(NULL, strLogPath.c_str());
	strLogPath.append(L"\\5funCafe.log");
	SET_XYLOG_PATH(strLogPath.c_str());
	SET_XYLOG_LEVEL(LEVEL_DEBUG);
	SET_PROCESS_NAME(L"5funCafe_Main");
	return true;
}

bool CheckInstance(HANDLE& hMutex)
{
	hMutex = CreateMutex(NULL, FALSE, MUTEX_NAME);
	if (hMutex)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			HWND hWnd = FindWindow(GUI_CLASS_NAME, MAIN_WND_NAME);
			if (hWnd)
				ActiveWnd(hWnd);
			return true;
		}
		return false;
	}
	return false;
}

bool InitDuilibRes(HINSTANCE hInstance)
{
	CPaintManagerUI::SetInstance(hInstance);
	CWndShadow::Initialize(hInstance);
#ifdef _DEBUG
	wstring strDir = L"Skin";
	wstring wstrResoucePath = CPaintManagerUI::GetInstancePath();
	wstrResoucePath += strDir;
	CPaintManagerUI::SetResourcePath(wstrResoucePath.c_str());
#else
	BYTE* pSkinBuffer = NULL;
	HRSRC hRes = ::FindResource(NULL, MAKEINTRESOURCE(IDR_DAT1), L"DAT");
	HGLOBAL hGlobal = ::LoadResource(NULL, hRes);
	DWORD dwSkinBufferSize = ::SizeofResource(NULL, hRes);
	BYTE* pResource = (BYTE*)::LockResource(hGlobal);
	CPaintManagerUI::SetResourceZip(pResource, dwSkinBufferSize);
#endif
	char strExeDir[512];
	strcpy_s(strExeDir, (PublicLib::UToA(CPaintManagerUI::GetInstancePath().GetData())).c_str());
	char* pStr = strrchr(strExeDir, '\\');
	pStr++;
	pStr[0] = '\0';
	//EmuManager::Instance()->setExePath(strExeDir);
	CGlobalData::Instance()->SetExePath(strExeDir);
	return true;
}

bool InitModules(HINSTANCE hInstance)
{
	//初始化全局变量
	OUTPUT_XYLOG(LEVEL_INFO, L"初始化全局数据模块");
	//...
	OUTPUT_XYLOG(LEVEL_INFO, L"初始化任务中心模块");
	//...
	return true;
}

void ExitModules()
{
	//....
	OUTPUT_XYLOG(LEVEL_INFO, L"反初始化模块完成");
}


void InitLoadBuffer()
{
	char strLoadImg[512];
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(strLoadImg, "%sloading\\loading%d.png", CGlobalData::Instance()->GetExePath().c_str(), i);
		LoadingBuffer* pBuffer = nullptr;
		pBuffer = CGlobalData::Instance()->GetLoadBuffer(i);
		CglesRender::loadImgBuffer(strLoadImg, pBuffer->pData, pBuffer->nWidth, pBuffer->nHeight);
		printf("loading--- %s %d %d\n", strLoadImg, pBuffer->nWidth, pBuffer->nHeight);
	}
}