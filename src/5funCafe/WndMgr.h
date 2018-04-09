#pragma once


class CWndBase;
class CWndMgr
{
public:
	static CWndMgr* Instance()
	{
		static CWndMgr obj;
		return &obj;
	}
	void SetDownloadWnd(HWND hWnd) { m_hDownloadWnd = hWnd; }
	void AddWnd(HWND hWnd, CWndBase* pWnd);
	void RemoveWnd(HWND hWnd);
	CWndBase* GetWndObject(HWND hWnd);
	void CloseAll();
	void ShowAll(bool bShow);

protected:
	CWndMgr();
	~CWndMgr();

private:
	HWND m_hDownloadWnd;
	map<HWND, CWndBase*> m_wndMap;
};

