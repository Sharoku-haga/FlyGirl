/**
*@file GameStage.h
*@brief �Q�[���X�e�[�W���Ǘ�����N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*@data 2016/09/14�C��
*/
#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include"LibClass.h"
#include"CommonItems.h"

/**�w�i�̃X�s�[�h*/
#define BG_MOVESPEED 1.f

/**�w�i�̐�*/
enum BackGroud
{
	ONE,
	TWO,
	BG_MAX
};

/**
*�Q�[���X�e�[�W�Ǘ��N���X
*
*/
class GameStage
{
private:

	/**�e�N�X�`���[���i�[*/
	Texture m_stageBackground;

	/**�w�i�̍��W*/
	D3DXVECTOR2 m_backGround[BG_MAX];

public:
	/**�R���X�g���N�^*/
	GameStage();

	/**�f�X�g���N�^*/
	~GameStage();

	/**�R���g���[���֐�*/
	void Control();

	/**�`��֐�*/
	void Draw();

};

#endif	// GAME_STAGE_H