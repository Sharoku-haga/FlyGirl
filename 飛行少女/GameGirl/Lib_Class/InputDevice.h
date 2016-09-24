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
	//�L�[�{�[�h�f�o�C�X
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;

public:
	//�R���X�g���N�^
	InputDevice();
	//�f�X�g���N�^
	~InputDevice();

	//Singleton�p�^�[��
	static InputDevice& GetInstance()
	{
		static InputDevice InputDevice;

		return InputDevice;
	}

	//DirectInput����
	HRESULT InitDinput();
	//�L�[�{�[�h�f�o�C�X�̏�����
	HRESULT InitDinputKey(HWND hWnd);

	//�L�[�{�[�h�f�o�C�X�擾
	LPDIRECTINPUTDEVICE8 GetKeyDevice();
};


#endif