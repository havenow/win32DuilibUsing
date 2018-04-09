#pragma once


enum ChildPage
{
	RpLoading = 0,
	RpError,
	RpFinish,
};


class IPage
{
public:
	virtual void Exit() = 0;
	virtual LRESULT OnMsg(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	virtual void OnTimer(int nTimerID) {}
	virtual int GetSelIndex() { return 0; }
	virtual void SetSelIndex(int nIndex) {}

};