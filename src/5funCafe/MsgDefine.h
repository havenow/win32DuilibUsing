#pragma once



//������������Ϣ
enum 
{
	WM_MAINWND_MSG_BEGIN = WM_USER + 1000,

	WM_MAINWND_MSG_GAMEHALL,
	WM_ENUMWND_MSG_UPDATE_ROOMID,
	WM_ENUMWND_MSG_PAGE_ROOM,
	WM_ENUMWND_MSG_GAMEHALL_ERROR,
	WM_ENUMWND_MSG_SETCOINS,
	WM_ENUMWND_MSG_SETPWD,
	WM_ENUMWND_MSG_ALLOWLOOK,
	WM_ENUMWND_MSG_PLAY_MODE_FAST,
	WM_ENUMWND_MSG_KICKINFO,
	WM_ENUMWND_MSG_START_GAME,

};


//WM_MAINWND_MSG_GAMEHALL
enum {
	WpConnectError = 0,	//�޷����ӵ�������
	WpLoginError,		//��¼ʧ��
	WpDisConnect,		//��������Ͽ�������
	WpJoinRoomError,	//���뷿��ʧ��
	WpPing,
	WpKickOut,
	WpTimeoutKickOut,
	WpDissolveRoom,
};

//WM_ENUMWND_MSG_PAGE_ROOM
enum {
	WpRoomInfo = 0,
	WpJoinRoom,
	WpIMEnterRoom,
	WpIMRecvMsg,
	WpIMSendMsg,
	WpIMError,
	WpIMAnnounce,
};