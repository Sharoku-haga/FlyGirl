#include <d3dx9.h>
#include <d3d9.h>
#include"GraphicsD3D.h"


//�R���X�g���N�^
GraphicsD3D::GraphicsD3D()
{
	m_pDirect3D = NULL;
	m_pD3Device = NULL;
}

//�f�X�g���N�^
GraphicsD3D :: ~GraphicsD3D()
{
	SAFE_RELEASE(m_pD3Device);
	SAFE_RELEASE(m_pDirect3D);
}

//DirectX�������֐�(���ŕ`��ݒ���s���Ă���)
HRESULT	 GraphicsD3D::InitDevice(HWND hWnd)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pDirect3D == NULL)
	{
		MessageBox(0, "Direct3D�̃C���^�[�t�F�C�X�̍쐬�Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&m_d3ddm);

	ZeroMemory(&m_d3dpp,sizeof(D3DPRESENT_PARAMETERS));

	m_d3dpp.BackBufferFormat = m_d3ddm.Format;
	m_d3dpp.BackBufferCount = 1;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.Windowed = TRUE;

	//�f�o�C�X�����
	m_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&m_d3dpp, &m_pD3Device);

	if (m_pD3Device == NULL)
	{
		MessageBox(0, "Direct3D�̃f�o�C�X�̍쐬�Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	//�`��ݒ�
	SetRenderState();
	
	return S_OK;
}

//�`��ݒ�
void GraphicsD3D::SetRenderState()
{
	// �`��̐ݒ�
	m_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	m_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

//�f�o�C�X�擾
IDirect3DDevice9* GraphicsD3D::GetDevice()
{
	return m_pD3Device;
}

//�`��J�n����
void GraphicsD3D::StartRender(DWORD FVF)
{
	//��ʂ̏���
	m_pD3Device->Clear(0, NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0x00, 0x00, 0x00),1.0, 0);
	//�`��̊J�n
	m_pD3Device->BeginScene();
	//�`��̃t�H�[�}�b�g��ݒ�
	m_pD3Device->SetFVF(FVF);
}

//�`��I������
void GraphicsD3D::EndRender()
{
	//�`��̏I�� 
	m_pD3Device->EndScene();

	//�\��
	m_pD3Device->Present(NULL, NULL, NULL, NULL);
}