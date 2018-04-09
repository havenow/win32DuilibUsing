#pragma once
#include "MsgDefine.h"


#define BEGIN_MSG_MAP()	\
protected: \
	virtual BOOL ProcessMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult)  \
{

//处理系统消息
#define DECLARE_MSG(msg, fun) \
if (msg == uMsg) \
{ \
	BOOL bHandled = FALSE; \
	lResult = fun(wParam, lParam, bHandled); \
	return bHandled; \
}

//处理自定义消息
#define DECLARE_USER_MSG(msg, fun) \
if (uMsg > WM_MAINWND_MSG_BEGIN && msg == uMsg) \
{ \
	lResult = fun(wParam, lParam); \
	return TRUE; \
}

#define END_MSG_MAP() \
	return FALSE; \
}

class CWndMain :
	public CWndBase
{
public:
	CWndMain();
	~CWndMain();

protected:
	virtual LPCWSTR GetWndName()const;
	virtual LPCWSTR GetXmlPath()const;

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	BEGIN_MSG_MAP()
		DECLARE_MSG(WM_COPYDATA, OnMsgCopyData)
		DECLARE_USER_MSG(WM_MAINWND_MSG_GAMEHALL, OnMsgGameHall)
	END_MSG_MAP()

	LRESULT OnMsgGameHall(WPARAM wParam, LPARAM lParam);
	LRESULT OnMsgCopyData(WPARAM wParam, LPARAM lParam, BOOL &bHandled);


	BEGIN_BIND_CTRL()
		BIND_CTRL(L"btn_sys_close", &CWndMain::OnNotifyBtnClose)
		BIND_CTRL(L"btn_sys_min", &CWndMain::OnNotifyBtnMin)
		BIND_CTRL(L"btn_sys_max", &CWndMain::OnNotifyBtnMax)
		BIND_CTRL(L"btn_sys_restore", &CWndMain::OnNotifyBtnRestore)
	END_BIND_CTRL()


	bool OnNotifyBtnClose(void* lpParam);
	bool OnNotifyBtnMin(void* lpParam);
	bool OnNotifyBtnMax(void* lpParam);
	bool OnNotifyBtnRestore(void* lpParam);

	void Exit();//程序退出唯一入口

private:

};

