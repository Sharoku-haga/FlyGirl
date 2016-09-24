/*
*ウィンドウ関連クラス
*
*/
#ifndef WINDOW_OBJECT_H
#define WINDOW_OBJECT_H
#include <windows.h>
/*
*ウィンドウ作成クラス
*
*/
class WindowObject
{
private:

	//ウィンドウクラス
	WNDCLASSEX m_wndc;
	//ウィンドウハンドル
	HWND m_hWnd;
	//ウィンドウのタイトル
	char* m_wTitle;
	//ウインドウの幅
	int m_wWidth;
	//ウィンドウの高さ
	int m_wHeight;

public:
	
	//コンストラクタ
	WindowObject(char* title,int width,int height);
	//デストラクタ
	~WindowObject();

	//ウィンドウ作成
	HRESULT MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp));

	//ハンドル取得用関数
	HWND GetHwnd();

};


#endif