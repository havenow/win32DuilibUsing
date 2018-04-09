#pragma once


/************************************************************************/
/* ����һЩȫ�ֱ���                                                     */
/************************************************************************/
#define DECLARE_STR(x,y)	static const wchar_t* x = y;


DECLARE_STR(GUI_CLASS_NAME,		L"GuiFoundation")

//��������
#ifdef APP_MAIN
DECLARE_STR(MAIN_WND_NAME,		L"����Ϸ�����ɰ�")
DECLARE_STR(MUTEX_NAME,			L"5funCafeMetux")
DECLARE_STR(NOTIFY_ICON_NAME,	L"����Ϸ��")
#endif

//���³�����
#ifdef APP_UPDATE
DECLARE_STR(UPDATE_WND_NAME,	L"����Ϸ�����³���")
#define SCRIPT_FILE_NAME	L"UpdateScript.XML"	//�����ļ�����
#endif

//ж�س�����
#ifdef APP_UNINSTALL
DECLARE_STR(UNINSTALL_WND_NAME, L"����Ϸ��ж�س���")
#endif

//��װ������
#ifdef APP_SETUP
DECLARE_STR(SETUP_WND_NAME,		L"����Ϸ����װ����")
#define SPACE_NEED			(200<<20)		//������Ҫ200M��װ�ռ�
#endif

//��������
#define EXE_MAIN			L"5funCafe.exe"
#define EXE_RENDER			L"5funCafeWeb.exe"
#define EXE_UNINSTALL		L"Uninstall.exe"
#define EXE_UPDATE			L"5funUpdate.exe"
#define EXE_BUGREPORT		L"5funBugReport.exe"
#define EXE_EMULATOR		L"5funEmulator.exe"
#define EXE_EMULATOR_PSP	L"PSPEmulator.exe"


#define SOFT_NAME			L"����Ϸ�����ɰ�"
#define SOFT_ROOT_DIR		L"5funCafe"

//��ݷ�ʽ����
#define SHORTCUT_MAIN_NAME	L"����Ϸ��"

//ע���������
#define REG_ROOT_NAME		L"5funCafe"

#define REG_COMPANY			L"�����γ�����Ƽ����޹�˾"
#define REG_URL				L"http://www.5fun.cn/"


//PC��������
#define PC_URL				L"http://pc.5fun.com/"