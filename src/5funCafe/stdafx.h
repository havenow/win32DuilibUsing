// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>
#include <shellapi.h>
#include <ShlObj.h>
#include <shlwapi.h>
#include <WinSock2.h>
#include <Tlhelp32.h>
#pragma comment(lib, "ws2_32.lib")
// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>
#include <process.h>
#include <stdint.h>
#include <map>
#include <list>
#include <algorithm>
using std::map;
using std::list;

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "../Duilib/UIlib.h"
using namespace DuiLib;



#include <AppHelper.h>
#include <AutoLock.h>
#include <PublicLib/XYLog.h>
#include <PublicLib/StrHelper.h>
#include <PublicLib/Common.h>
#include <PublicLib/json/json-forwards.h>
#include <PublicLib/json/json.h>
#include <PublicLib/md5.h>
#include <PublicLib/HttpClient.h>
#include <PublicLib/Markup.h>
#include <PublicLib/System.h>
#include <PublicLib/FileHelper.h>

#include "WndBase.h"
#include <SoftDefine.h>