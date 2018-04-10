#pragma once



//������������Ϣ
enum
{
	WM_MAINWND_MSG_BEGIN = WM_USER + 1000,

	WM_MAINWND_MSG_GAMEHALL,
	WM_MAINWND_MSG_UPDATE_ROOMID,
	WM_MAINWND_MSG_GAMEHALL_ERROR,
	WM_MAINWND_MSG_SETCOINS,
	WM_MAINWND_MSG_SETPWD,
	WM_MAINWND_MSG_ALLOWLOOK,
	WM_MAINWND_MSG_PLAY_MODE_FAST,
	WM_MAINWND_MSG_KICKINFO,
	WM_MAINWND_MSG_START_GAME,


	//���巿��ҳ����Ϣ
	WM_MAINWND_MSG_PAGE_ROOM_BEGIN,
	WM_MAINWND_MSG_PAGE_ROOM,
	
	WM_MAINWND_MSG_PAGE_ROOM_END,
	//����ģ����ҳ����Ϣ
	WM_MAINWND_MSG_PAGE_EMULATOR_BEGIN,
	
	WM_MAINWND_MSG_PAGE_EMULATOR_END,

	//������Ϣ����Ҫ���⴦��
	WM_MAINWND_MSG_TASK_BEGIN,
	WM_MAINWND_MSG_GUEST_LOGIN,
	WM_MAINWND_MSG_TASK_END,
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