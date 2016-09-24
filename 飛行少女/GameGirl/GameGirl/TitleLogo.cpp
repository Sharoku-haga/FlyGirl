/**
*@file TitleLogo.cpp
*@brief �^�C�g�����S�i�w�i�j�N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"TitleLogo.h"

// �R���X�g���N�^
TitleLogo::TitleLogo()
{
	// �e�N�X�`���[��ǂݍ���
	m_titleLogoTex.LoadTex("Picture\\TitleScene\\Title.png");
}

// �f�X�g���N�^
TitleLogo::~TitleLogo()
{

}

// �`��֐�
void TitleLogo::Draw()
{
	// �^�C�g�����S�̒��_���
	CUSTOMVERTEX titlelogo[] = {
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	// �^�C�g�����S��`��
	m_titleLogoTex.RenderTex(titlelogo);
}