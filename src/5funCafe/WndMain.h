#pragma once

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
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) { return 0; };

private:

};

