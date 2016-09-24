#include <dinput.h>
#include"InputDevice.h"

//�R���X�g���N�^
InputDevice::InputDevice()
{
	m_pDInput = NULL;
	m_pKeyDevice = NULL;
}

//�f�X�g���N�^(�����Ńf�o�C�X�Ȃǂ��J�����Ă���)
InputDevice::~InputDevice()
{
	if (m_pKeyDevice)
	{
		m_pKeyDevice->Release();
		m_pKeyDevice = NULL;
	}
	
	if (m_pDInput)
	{
		m_pDInput->Release();
		m_pDInput = NULL;
	}

}

//DirectInput����
HRESULT InputDevice::InitDinput()
{
	//	DirectInput �I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDInput, NULL)))
	{
		MessageBox(0, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

//�L�[�{�[�h�f�o�C�X������
HRESULT InputDevice::InitDinputKey(HWND hWnd)
{

	//	�L�[�{�[�h�̏�����
	if (FAILED(m_pDInput->CreateDevice(GUID_SysKeyboard,
		&m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInput�L�[�{�[�h�������Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	//	�f�[�^�t�H�[�}�b�g
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//	�������x��
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	m_pKeyDevice->Acquire();
	return S_OK;
}

//�L�[�{�[�h�f�o�C�X�擾
LPDIRECTINPUTDEVICE8 InputDevice::GetKeyDevice()
{
	return m_pKeyDevice;
}
