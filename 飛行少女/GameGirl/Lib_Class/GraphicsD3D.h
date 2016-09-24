/**
*@file GraphicsD3D.h
*
*/
#ifndef GRAPHIC_D3D_H
#define GRAPHIC_D3D_H

#include <d3d9.h>
#include <d3dx9.h>

#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

/**
*DirectXのデバイス関連のクラス
*/
class GraphicsD3D
{
private:
	//	Direct3Dのインターフェイス
	IDirect3D9*			m_pDirect3D;
	//	Direct3Dのデバイス
	IDirect3DDevice9*	m_pD3Device;
	// ディスプレイ....ローカルでいいかも
	D3DDISPLAYMODE m_d3ddm;
	//	パラメーター....ローカルでいいかも
	D3DPRESENT_PARAMETERS m_d3dpp;

public:
	/**
	*コンストラクタ＆デストラクタ
	*/
	GraphicsD3D();
	~GraphicsD3D();

	//Singletonパターン
	static GraphicsD3D& GetInstance()
	{
		static GraphicsD3D graphicsDevice;
		return graphicsDevice;
	}

	//DirectX初期化関数
	HRESULT	 InitDevice(HWND hWnd);
	//RenderStateの初期設定
	void SetRenderState();

	//デバイス取得
	IDirect3DDevice9* GetDevice();
	//描画開始処理
	void StartRender(DWORD FVF);
	//描画終了処理
	void EndRender();

};



#endif