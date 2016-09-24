/**
*@file InputDevice.h
*
*
*/
#ifndef INPUT_DEVICE_H
#define	INPUT_DEVICE_H

#include <dinput.h>
/*
*
*/
class InputDevice
{
private:
	//DirectInput
	LPDIRECTINPUT8 m_pDInput;
	//キーボードデバイス
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;

public:
	//コンストラクタ
	InputDevice();
	//デストラクタ
	~InputDevice();

	//Singletonパターン
	static InputDevice& GetInstance()
	{
		static InputDevice InputDevice;

		return InputDevice;
	}

	//DirectInput生成
	HRESULT InitDinput();
	//キーボードデバイスの初期化
	HRESULT InitDinputKey(HWND hWnd);

	//キーボードデバイス取得
	LPDIRECTINPUTDEVICE8 GetKeyDevice();
};


#endif