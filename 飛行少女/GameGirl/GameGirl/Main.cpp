/**
*@file Main.cpp
*@brief ゲームのエントリーポイントのcpp.
*/
#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include <crtdbg.h>
#include"LibClass.h"
#include"CommonItems.h"
#include"SceneManager.h"

// ウィンドウ名
#define WINDOW_TITLE TEXT("少女大飛行")	
// ゲームFPS
#define GAME_FPS 1000 / 60


// ウインドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// グラフィックデバイス
GraphicsD3D* g_GraphicDevice = NULL;
// インプットデバイス
InputDevice* g_InputDevice = NULL;


// エントリポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//------------------------------------------------------
	//					ウィンドウ生成
	//------------------------------------------------------
	MSG msg;
	WindowObject gameWindow(WINDOW_TITLE, WINDOW_W, WINDOW_H);
	gameWindow.MakeWindow(hInstance, WindowProc);

	//-------------------------------------------------------
	//					DirectXの初期化
	//-------------------------------------------------------
	// インスタンスを取得
	g_GraphicDevice = &GraphicsD3D::GetInstance();

	// デバイス取得
	g_GraphicDevice->InitDevice(gameWindow.GetHwnd());


	//--------------------------------------------------------
	//			DirectInput＆キーボードの初期化
	//--------------------------------------------------------

	// インスタンス取得
	g_InputDevice = &InputDevice::GetInstance();
	// デバイス取得
	g_InputDevice->InitDinput();
	// キーボードデバイス取得
	g_InputDevice->InitDinputKey(gameWindow.GetHwnd());

	//--------------------------------------------------------
	//					ゲームループ
	//--------------------------------------------------------

	SceneManager* pSceneManager = new SceneManager();


	DWORD SyncOld = timeGetTime();	//	システム時間を取得
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
			if (SyncNow - SyncOld >= GAME_FPS) //	1秒間に60回この中に入る
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

// ウインドウプロシージャ
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