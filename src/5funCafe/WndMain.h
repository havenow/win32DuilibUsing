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

private:

};

