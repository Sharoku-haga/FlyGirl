/**
*@file Texture.h
*
*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <d3dx9.h>
#include <d3d9.h>
#include"GraphicsD3D.h"

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};


/**
*�e�N�X�`���[���Ǘ�����N���X
*
*/
class Texture
{
private:
	//�e�N�X�`���[���i�[
	LPDIRECT3DTEXTURE9	m_pTexture;
	//�f�o�C�X�i�[�p
	IDirect3DDevice9*	m_pD3Device;

public:
	
	//�R���X�g���N�^
	Texture();
	//�f�X�g���N�^
	~Texture();

	//�摜�ǂݍ���
	HRESULT LoadTex(char* text);

	//�摜�ǂݍ���Ex
	HRESULT LoadTexEx(char* text,int a,int r,int g,int b,bool size);

	//�摜�`��
	void RenderTex(CUSTOMVERTEX* setdraw);

	//�f�o�C�X���擾����֐�(static�p)
	void GetDevice();

	//�e�N�X�`���[���i�[���Ă��邩���m�F
	LPDIRECT3DTEXTURE9 GetStateTex(){ return m_pTexture; }

};


#endif