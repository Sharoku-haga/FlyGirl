/**
*@file GameScene.h
*@brief �Q�[���V�[���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"GameScreenFrame.h"
#include"GameStage.h"
#include"GamePlayer.h"
#include "EnemyPatternManager.h"
/**
*�Q�[���V�[�����Ǘ�����N���X<br>
*
*/
class GameScene : public Scene
{
private:

	//��ʂ̘g�N���X
	GameScreenFrame m_screenFrame;

	//�Q�[���X�e�[�W(�w�i)�N���X
	GameStage m_gameStage;

	//�Q�[���v���C���[�N���X
	GamePlayer m_gamePlayer;

	//�G�̃p�^�[�����Ǘ�����N���X
	EnemyPatternManager m_enemyPatternManager;

public:
	//�R���X�g���N�^
	GameScene();

	//�f�X�g���N�^
	virtual ~GameScene();

	//�R���g���[���֐�
	virtual SceneID Control();

	//�`��֐�
	virtual void Draw();

};


#endif