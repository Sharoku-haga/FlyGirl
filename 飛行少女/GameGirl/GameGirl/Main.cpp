/**
*@file Main.cpp
*@brief �Q�[���̃G���g���[�|�C���g��cpp.
*/
#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include <crtdbg.h>
#include"LibClass.h"
#include"CommonItems.h"
#include"SceneManager.h"

// �E�B���h�E��
#define WINDOW_TITLE TEXT("�������s")	
// �Q�[��FPS
#define GAME_FPS 1000 / 60


// �E�C���h�E�v���V�[�W��
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// �O���t�B�b�N�f�o�C�X
GraphicsD3D* g_GraphicDevice = NULL;
// �C���v�b�g�f�o�C�X
InputDevice* g_InputDevice = NULL;


// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// ���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//------------------------------------------------------
	//					�E�B���h�E����
	//------------------------------------------------------
	MSG msg;
	WindowObject gameWindow(WINDOW_TITLE, WINDOW_W, WINDOW_H);
	gameWindow.MakeWindow(hInstance, WindowProc);

	//-------------------------------------------------------
	//					DirectX�̏�����
	//-------------------------------------------------------
	// �C���X�^���X���擾
	g_GraphicDevice = &GraphicsD3D::GetInstance();

	// �f�o�C�X�擾
	g_GraphicDevice->InitDevice(gameWindow.GetHwnd());


	//--------------------------------------------------------
	//			DirectInput���L�[�{�[�h�̏�����
	//--------------------------------------------------------

	// �C���X�^���X�擾
	g_InputDevice = &InputDevice::GetInstance();
	// �f�o�C�X�擾
	g_InputDevice->InitDinput();
	// �L�[�{�[�h�f�o�C�X�擾
	g_InputDevice->InitDinputKey(gameWindow.GetHwnd());

	//--------------------------------------------------------
	//					�Q�[�����[�v
	//--------------------------------------------------------

	SceneManager* pSceneManager = new SceneManager();


	DWORD SyncOld = timeGetTime();	//	�V�X�e�����Ԃ��擾
	DWORD SyncNow;

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= GAME_FPS) //	1�b�Ԃ�60�񂱂̒��ɓ���
			{
				if (pSceneManager->RunGame())
				{
					break;
				}

				SyncOld = SyncNow;
			}
		}
	}
	
	delete pSceneManager;

}

// �E�C���h�E�v���V�[�W��
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return  0;
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
			break;
		}
		break;
	
	}
	return  DefWindowProc(hWnd, message, wParam, lParam);
}