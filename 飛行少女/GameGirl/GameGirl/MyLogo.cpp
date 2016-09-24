/**
*@file MyLogo.cpp
*@brief ���S�̃R���g���[����`����Ǘ�����N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"MyLogo.h"


//�R���X�g���N�^
MyLogo::MyLogo()
{
	//���S�̃e�N�X�`���[��ǂݍ���
	m_Logo.LoadTexEx("Picture\\LogoScene\\MyLogo.png",255,0,0,0,false);
	//���S�̃e�N�X�`���[��ǂݍ���
	//m_Logo.LoadTexEx("val.jpg",255,0,0,0,true);
	//m_Logo.LoadTex("val.jpg");
}

//�f�X�g���N�^
MyLogo::~MyLogo()
{

}

//���S�̕`��
void MyLogo::Draw()
{
	
	//���S�̒��_���
	CUSTOMVERTEX logo[] ={
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	//�`��
	m_Logo.RenderTex(logo);
	
}


