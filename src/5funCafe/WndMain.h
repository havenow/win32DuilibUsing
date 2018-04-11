#pragma once
#include "MsgDefine.h"
#include "IPage.h"
#include "UICefWebkit.h"



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

#define BEGIN_USER_MSG if (uMsg > WM_MAINWND_MSG_BEGIN) { \
	switch (uMsg) \
	{ \

#define END_USER_MSG \
	default: break; \
	} \
	return TRUE; \
}
//处理自定义消息
#define DECLARE_USER_MSG(msg, fun) \
	case msg: lResult = fun(wParam, lParam); break;

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
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	BEGIN_MSG_MAP()
		DECLARE_MSG(WM_COPYDATA, OnMsgCopyData)
		DECLARE_MSG(WM_SIZE, OnMsgSize)
		DECLARE_MSG(WM_TIMER, OnMsgTimer)
		BEGIN_USER_MSG
			DECLARE_USER_MSG(WM_MAINWND_MSG_GAMEHALL, OnMsgGameHall)
			DECLARE_USER_MSG(WM_MAINWND_MSG_PAGE_ROOM, OnMsgPageRoom)
		END_USER_MSG
	END_MSG_MAP()

	LRESULT OnMsgGameHall(WPARAM wParam, LPARAM lParam);
	LRESULT OnMsgPageRoom(WPARAM wParam, LPARAM lParam);
	LRESULT OnMsgCopyData(WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnMsgSize(WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnMsgTimer(WPARAM wParam, LPARAM lParam, BOOL &bHandled);


	BEGIN_INIT_CTRL()
		DECLARE_CTRL(m_pLblGameName, L"lbl_game_name")
		DECLARE_CTRL(m_pLblUserID, L"lbl_user_id")
		DECLARE_CTRL_TYPE(m_pWebTable, CCefWebkitUI, L"web_table")
	END_INIT_CTRL()

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
	bool m_bExit;
	IPage *m_pPageRoom;
	IPage *m_pPageWeb;
	IPage *m_pPageEmulator;
	CControlUI *m_pLblGameName;
	CControlUI *m_pLblUserID;
	CCefWebkitUI *m_pWebTable;
};

