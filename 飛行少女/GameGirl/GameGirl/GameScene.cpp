/**
*@file GameScene.cpp
*@brief �Q�[���V�[���N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"GameScene.h"

// �R���X�g���N�^
GameScene::GameScene()
{

}

// �f�X�g���N�^
GameScene::~GameScene()
{

}


// �R���g���[���֐�
SceneID GameScene::Control()
{
	// �w�i�̃R���g���[��
	m_gameStage.Control();

	
	// �G�̃p�^�[���}�l�[�W���[(�G�̃p�^�[���S�Ă��I�������V�[�����I������)
	if (m_enemyPatternManager.Control())
	{
		return Title_scene;
	}
	
	// �v���C���[�R���g���[��(���S�t���O�������Ă�����V�[�����I������)
	if (m_gamePlayer.Control())
	{
		return Title_scene;
	}

	return Game_scene;
}


// �`��֐�
void GameScene::Draw()
{
	// �w�i�̕`��
	m_gameStage.Draw();
	
	// �v���C���[�̕`��
	m_gamePlayer.Draw();

	// �G�̕`��
	m_enemyPatternManager.Draw();;

	// ��ʘg�̕`��
	m_screenFrame.Draw();
}