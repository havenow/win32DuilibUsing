#pragma once

enum GameType
{
	GameUnknow = 0,
	GameFBA = 31,	//街机
	GameNDS,		//NDS
	GameGBA,		//GBA
	GamePSP,
	GameFC,
	GameSFC = 43,
	GameMD = 51,
	GameGBAEx,		//GBA加强版
	GamePS,
	GameWSC,
	GameGBC = 56,
	GameN64,
	GameONS,
	GameDC = 60,
};

#ifndef _TAG_LOADINGBUFFER
#define _TAG_LOADINGBUFFER
typedef struct _tagLoadingBuffer
{
	char	pData[1024 * 1024 * 2];
	int		nWidth;
	int		nHeight;
}LoadingBuffer;
#endif

class CGlobalData
{
public:
	static CGlobalData* Instance()
	{
		static CGlobalData obj;
		return &obj;
	}
	void Init();
	void Exit();

	int GetRoomID() const { return m_nRoomID; }
	void SetRoomID(int val) { m_nRoomID = val; }
	int GetRoomCategory() const { return m_nRoomCategory; }
	void SetRoomCategory(int val) { m_nRoomCategory = val; }
	__int64 GetGameID() const { return m_nGameID; }
	void SetGameID(__int64 val) { m_nGameID = val; }
	const wstring &GetDeviceID() const { return m_strDeviceID; }
	const wstring &GetRunPath() const { return m_strRunPath; }
	const wstring &GetAppVersion() const { return m_strAppVersion; }
	const wstring &GetOSType() const { return m_strOSType; }
	const wstring &GetMacAddr() const { return m_strMacAddr; }
	const wstring &GetOSName() const { return m_strOSName; }
	const wstring &GetOSVersion() const { return m_strOSVersion; }
	//const string &GetRoomPwd() const { return m_strRoomPwd; }
	//void SetRoomPwd(const string &val) { m_strRoomPwd = val; }
	string GetExePath() const { return m_exePath; }
	void SetExePath(string val) { m_exePath = val; }
	LoadingBuffer* GetLoadBuffer(int nIndex);

protected:
	CGlobalData();
	~CGlobalData();
	CGlobalData(const CGlobalData& obj){}

private:
	int	m_nRoomID;//加入房间时，保存的房间ID
	__int64 m_nGameID;
	int m_nRoomCategory;
	wstring m_strDeviceID;
	wstring m_strRunPath;
	wstring m_strAppVersion;
	wstring m_strOSName;
	wstring m_strOSVersion;
	wstring m_strOSType;
	wstring m_strMacAddr;
	//string m_strRoomPwd;//房间密码
	string m_exePath; 
	LoadingBuffer m_LoadingBuffer[3];
};

