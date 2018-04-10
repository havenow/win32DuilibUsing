#pragma once
#include "utils/thread.hpp"
#include "utils/Timestamp.hpp"

#include <queue>
#include <windows.h>
using namespace std;

class CRenderThread :
	public Thread
{
private:
	unsigned int	m_nFrameCount = 0;
	double			m_lfTime = 0.016666;
	HWND			m_hWnd;
	HWND			m_hMainWnd;
	HINSTANCE		m_hInstance;

	bool			Create(HINSTANCE hInst, HWND hParent);
	void			Show(const bool bShow = true);
	bool			InitGLES();

protected:
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL InitInstance(HINSTANCE hInstance);

public:
	CRenderThread(void);
	~CRenderThread(void);

	virtual void join();
	virtual bool run();
	virtual bool start();

	bool	InvolkEmu();
	void	SetInstance(HINSTANCE hInstance) { m_hInstance = hInstance; }
	void	SetMainWnd(HWND hWnd) { m_hMainWnd = hWnd; }
	HWND	GetWnd()const { return m_hWnd; }
	HWND	GetMainWnd()const { return m_hMainWnd; }
	int		GetFrameCount() {return m_nFrameCount;}
	void	SetCoreLoopTime(double	lfTime) { m_lfTime = lfTime; }
	DWORD	GetThreadId() { return Thread::getThreadId(); }
};

