#include <dinput.h>
#include"InputDevice.h"

//コンストラクタ
InputDevice::InputDevice()
{
	m_pDInput = NULL;
	m_pKeyDevice = NULL;
}

//デストラクタ(ここでデバイスなどを開放している)
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

//DirectInput生成
HRESULT InputDevice::InitDinput()
{
	//	DirectInput オブジェクトの作成
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDInput, NULL)))
	{
		MessageBox(0, "DirectInputオブジェクト生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

//キーボードデバイス初期化
HRESULT InputDevice::InitDinputKey(HWND hWnd)
{

	//	キーボードの初期化
	if (FAILED(m_pDInput->CreateDevice(GUID_SysKeyboard,
		&m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInputキーボード初期化に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	//	データフォーマット
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//	協調レベル
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	m_pKeyDevice->Acquire();
	return S_OK;
}

//キーボードデバイス取得
LPDIRECTINPUTDEVICE8 InputDevice::GetKeyDevice()
{
	return m_pKeyDevice;
}
