#include <d3dx9.h>
#include <d3d9.h>
#include"GraphicsD3D.h"


//コンストラクタ
GraphicsD3D::GraphicsD3D()
{
	m_pDirect3D = NULL;
	m_pD3Device = NULL;
}

//デストラクタ
GraphicsD3D :: ~GraphicsD3D()
{
	SAFE_RELEASE(m_pD3Device);
	SAFE_RELEASE(m_pDirect3D);
}

//DirectX初期化関数(中で描画設定も行っている)
HRESULT	 GraphicsD3D::InitDevice(HWND hWnd)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pDirect3D == NULL)
	{
		MessageBox(0, "Direct3Dのインターフェイスの作成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&m_d3ddm);

	ZeroMemory(&m_d3dpp,sizeof(D3DPRESENT_PARAMETERS));

	m_d3dpp.BackBufferFormat = m_d3ddm.Format;
	m_d3dpp.BackBufferCount = 1;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.Windowed = TRUE;

	//デバイスを作る
	m_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&m_d3dpp, &m_pD3Device);

	if (m_pD3Device == NULL)
	{
		MessageBox(0, "Direct3Dのデバイスの作成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	//描画設定
	SetRenderState();
	
	return S_OK;
}

//描画設定
void GraphicsD3D::SetRenderState()
{
	// 描画の設定
	m_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	m_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

//デバイス取得
IDirect3DDevice9* GraphicsD3D::GetDevice()
{
	return m_pD3Device;
}

//描画開始処理
void GraphicsD3D::StartRender(DWORD FVF)
{
	//画面の消去
	m_pD3Device->Clear(0, NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0x00, 0x00, 0x00),1.0, 0);
	//描画の開始
	m_pD3Device->BeginScene();
	//描画のフォーマットを設定
	m_pD3Device->SetFVF(FVF);
}

//描画終了処理
void GraphicsD3D::EndRender()
{
	//描画の終了 
	m_pD3Device->EndScene();

	//表示
	m_pD3Device->Present(NULL, NULL, NULL, NULL);
}