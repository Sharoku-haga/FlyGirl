/**
*@file GameStage.cpp
*@brief �Q�[���X�e�[�W���Ǘ�����N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"GameStage.h"

//�R���X�g���N�^
GameStage::GameStage()
{
	m_stageBackground.LoadTexEx("Picture\\GameScene\\GameStage\\Stage01.png", 255, 0, 0, 0, false);

	//�P���ڂ̔w�i�̏�����
	m_backGround[ONE].x = GAMESTAGE_POS_X;
	m_backGround[ONE].y = GAMESTAGE_POS_Y;


	//�Q���ڂ̔w�i������
	m_backGround[TWO].x = GAMESTAGE_POS_X;
	m_backGround[TWO].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);

}

//�f�X�g���N�^
GameStage::~GameStage()
{

}

//�R���g���[���֐�
void GameStage::Control()
{
	//�w�i�X�s�[�h
	m_backGround[ONE].y += BG_MOVESPEED;
	m_backGround[TWO].y += BG_MOVESPEED;


	//��ʂ̉��܂ł����Ə�ɃV�t�g����
	//��ʂ̉��܂ł��������փV�t�g����
	if (m_backGround[ONE].y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
	{
		m_backGround[ONE].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);
	}

	if (m_backGround[TWO].y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
	{
		m_backGround[TWO].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);
	}


}

//�`��֐�
void GameStage::Draw()
{
	//�w�i�̒��_���
	CUSTOMVERTEX stage[] = {
		{           0,           0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ GAMESTAGE_W,           0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ GAMESTAGE_W, GAMESTAGE_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{           0, GAMESTAGE_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	//�w�i1���ڂ̕`��
	CUSTOMVERTEX drawTex01[VERTEX_NUMBER];
	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawTex01[i] = stage[i];

		drawTex01[i].x += m_backGround[ONE].x;
		drawTex01[i].y += m_backGround[ONE].y;

	}
	m_stageBackground.RenderTex(drawTex01);


	//�w�i�Q���ڂ̕`��
	CUSTOMVERTEX drawTex02[VERTEX_NUMBER];
	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawTex02[i] = stage[i];

		drawTex02[i].x += m_backGround[TWO].x;
		drawTex02[i].y += m_backGround[TWO].y;

	}
	m_stageBackground.RenderTex(drawTex02);
}