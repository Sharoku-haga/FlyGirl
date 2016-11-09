/**
* @file main.cpp
* @brief 少女大飛行のmain.cpp
* @author haga
*/
#include <windows.h>
#include <crtdbg.h>
#include "resource.h"
#include "GameLib/GameLib.h"

//#define FULLSCREEN

#define GAME_TITLE TEXT("少女大飛行")		// ゲームタイトル
#define CLIENT_W 1280						// クライアント領域の幅
#define CLIENT_H 960						// クライアント領域の高さ
#define GAME_FPS (1000 / 60)				// FPS


// ウインドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// エントリポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	//------------------------------------------------------------
	//					ゲームの初期設定
	//------------------------------------------------------------


#ifndef FULLSCREEN

	GameLib::Instance().InitGameLib(GAME_TITLE, CLIENT_W, CLIENT_H, WindowProc, true, true, IDI_ICON1);

#else
	GameLib::Instance().InitGameLib(GAME_TITLE, CLIENT_W, CLIENT_H, WindowProc, false,true, IDI_ICON1);

#endif

	//------------------------------------------------------------
	//					ゲームループ
	//------------------------------------------------------------

	DWORD currentTime = timeGetTime();		// 現在の時間
	DWORD oldTime = timeGetTime();			// 前の時間

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			currentTime = timeGetTime();
			if (currentTime - oldTime >= GAME_FPS)
			{
				
				oldTime = timeGetTime();
			}
		}
	}

	GameLib::Instance().ReleaseGameLib();	// ライブラリ内のメモリ開放

	return (INT)msg.wParam;

}

// ウインドウプロシージャ関数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return  0;
	}
	break;
	case WM_KEYDOWN:
		switch ((CHAR)wparam)
		{
		case VK_ESCAPE:
		{
			int answer = MessageBox(hwnd, TEXT("終わりますか？"), TEXT("終了"), MB_YESNO);
			if (answer == IDYES)
			{
				PostQuitMessage(0);
				return 0;
			}
		}

		break;
		}
		break;

	case WM_SYSKEYDOWN:     // Alt + 特殊キーの処理に使う
		switch ((CHAR)wparam)
		{
		case VK_RETURN:     // Alt + Enterを押すとウィンドウ切り替え
			GameLib::Instance().ChangeWindowMode();
			break;
		default:
			break;
		}
		break;

	case WM_ACTIVATE:
		switch ((CHAR)wparam)
		{
		case WA_ACTIVE:
		case WA_CLICKACTIVE:

			break;
		}
	}
	return  DefWindowProc(hwnd, message, wparam, lparam);
}