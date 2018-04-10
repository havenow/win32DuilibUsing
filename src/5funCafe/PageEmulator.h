#pragma once
#include "IPage.h"



class CPageEmulator :
	public CHorizontalLayoutUI,
	public IPage
{
public:
	CPageEmulator();
	~CPageEmulator();

protected:
	virtual void Init();
	virtual void Exit();
	virtual LRESULT OnMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);

	bool OnNotifyOptBasicKey(void* lpParam);
	bool OnNotifyOptComposeKey(void* lpParam);
	bool OnNotifyBtnCoin(void* lpParam);
	bool OnNotifyBtnStart(void* lpParam);

	BEGIN_INIT_CTRL()
		DECLARE_CTRL_TYPE_PAGE(m_pTabKey, CTabLayoutUI, L"tab_key_setting")

	END_INIT_CTRL()
		BEGIN_BIND_CTRL()
		DECLARE_CTRL_BIND_PAGE(m_pOptBasicKey, COptionUI, L"opt_basic_key", &CPageEmulator::OnNotifyOptBasicKey);
	DECLARE_CTRL_BIND_PAGE(m_pOptComposeKey, COptionUI, L"opt_compose_key", &CPageEmulator::OnNotifyOptComposeKey);
		BIND_CTRL_PAGE(L"btn_coin", &CPageEmulator::OnNotifyBtnCoin)
		BIND_CTRL_PAGE(L"btn_start", &CPageEmulator::OnNotifyBtnStart)
	END_BIND_CTRL()

private:
	COptionUI*		m_pOptBasicKey;
	COptionUI*		m_pOptComposeKey;
	CTabLayoutUI*	m_pTabKey;

};

