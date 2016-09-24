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
*DirectX�̃f�o�C�X�֘A�̃N���X
*/
class GraphicsD3D
{
private:
	//	Direct3D�̃C���^�[�t�F�C�X
	IDirect3D9*			m_pDirect3D;
	//	Direct3D�̃f�o�C�X
	IDirect3DDevice9*	m_pD3Device;
	// �f�B�X�v���C....���[�J���ł�������
	D3DDISPLAYMODE m_d3ddm;
	//	�p�����[�^�[....���[�J���ł�������
	D3DPRESENT_PARAMETERS m_d3dpp;

public:
	/**
	*�R���X�g���N�^���f�X�g���N�^
	*/
	GraphicsD3D();
	~GraphicsD3D();

	//Singleton�p�^�[��
	static GraphicsD3D& GetInstance()
	{
		static GraphicsD3D graphicsDevice;
		return graphicsDevice;
	}

	//DirectX�������֐�
	HRESULT	 InitDevice(HWND hWnd);
	//RenderState�̏����ݒ�
	void SetRenderState();

	//�f�o�C�X�擾
	IDirect3DDevice9* GetDevice();
	//�`��J�n����
	void StartRender(DWORD FVF);
	//�`��I������
	void EndRender();

};



#endif