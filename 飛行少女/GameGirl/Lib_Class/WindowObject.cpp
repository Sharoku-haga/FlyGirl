#include <windows.h>
#include"WindowObject.h"


//コンストラクタ
WindowObject::WindowObject(char* title, int width, int height)
{
	
	m_hWnd = NULL;
	m_wTitle = title;
	m_wWidth = width;
	m_wHeight = height;
}

//デストラクタ
WindowObject::~WindowObject()
{

}

//ウィンドウ作成
HRESULT WindowObject::MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp))
{
	//Windows情報の設定
	m_wndc.cbSize = sizeof(m_wndc);
	m_wndc.style = CS_HREDRAW | CS_VREDRAW;
	m_wndc.lpfnWndProc = WndProc;
	m_wndc.cbClsExtra = m_wndc.cbWndExtra = 0;
	m_wndc.hInstance = hInstance;
	m_wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_wndc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_wndc.lpszMenuName = NULL;
	m_wndc.lpszClassName = m_wTitle;
	m_wndc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	if (!RegisterClassEx(&m_wndc))
	{
		MessageBox(0, "ウィンドウクラスの設定に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}
	//	ウィンドウを作る
	m_hWnd = CreateWindow(
		m_wTitle,								//ウィンドウのクラス名
		m_wTitle, 							//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		m_wWidth,							// Width（幅）　
		m_wHeight,							// Height（高さ)
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
		);

	
	//クライアント領域を調整する
	RECT client_rect;
	RECT widow_rect;
	GetWindowRect(m_hWnd, &widow_rect);
	GetClientRect(m_hWnd, &client_rect);

	//正しいウィンドウ間隔を求める(幅)
	widow_rect.right -= widow_rect.left;
	client_rect.right -= client_rect.left;

	//正しいウィンドウ間隔を求める(高さ)
	widow_rect.bottom -= widow_rect.top;
	client_rect.bottom -= client_rect.top;

	SetWindowPos(m_hWnd, HWND_TOP, 0, 0, (m_wWidth + (widow_rect.right - client_rect.right)), (m_wHeight + (widow_rect.bottom - client_rect.bottom)), SWP_NOMOVE);

	if (!m_hWnd)
	{
		MessageBox(0, "ウィンドウ生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	ShowWindow(m_hWnd, SW_SHOW);
	return S_OK;
}

//ハンドル取得用関数
HWND WindowObject::GetHwnd()
{
	return m_hWnd;
}
