// 5funCafe.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "5funCafe.h"


bool InitLog();
bool CheckInstance(HANDLE& hMutex);
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
		OutputDebugString(L"�Ѿ���һ��ʵ���������У��˳�\n");
		return 0;
	}
	PublicLib::EnableDebugPrivilege();

	InitLog();

	return 0;
}


bool InitLog()
{
	//��ʼ��XYClient��־
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