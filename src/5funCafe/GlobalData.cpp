#include "stdafx.h"
#include "GlobalData.h"



CGlobalData::CGlobalData()
: m_nRoomID(0)
, m_nRoomCategory(0)
, m_nGameID(0)
{
}


CGlobalData::~CGlobalData()
{
}

void CGlobalData::Init()
{

	m_nGameID = 509474702;

	m_strRunPath = GetRunPathW();
	m_strAppVersion = GetApplicationVersion();
	PublicLib::GetOSVersion(m_strOSName, m_strOSVersion);
	m_strOSType = PublicLib::Is64bitSystem() ? L"64" : L"32";
	PublicLib::GetMacAddress(m_strMacAddr);
	GetDeviceGuid(m_strDeviceID);
}

void CGlobalData::Exit()
{

}

LoadingBuffer* CGlobalData::GetLoadBuffer(int nIndex)
{
	if (nIndex > -1 && nIndex < 3)
		return &m_LoadingBuffer[nIndex];
	else
		return nullptr;
}
