/**
*@file GameScreenFrame.cpp
*@brief �Q�[����ʂ̘g�N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/19�`��֐���������
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"GameScreenFrame.h"

//�R���X�g���N�^
GameScreenFrame::GameScreenFrame()
{
	m_screenFarame.LoadTexEx("Picture\\GameScene\\GameScreenFrame\\GameSceneFrame.png",255,0,0,0,false);
}

//�f�X�g���N�^
GameScreenFrame::~GameScreenFrame()
{

}

//�`��֐�
void GameScreenFrame::Draw()
{
	//�X�N���[���t���[���̒��_���
	CUSTOMVERTEX screenFrame[] = {
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};
	m_screenFarame.RenderTex(screenFrame);
}
