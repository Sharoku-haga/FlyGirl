/**
*@file TitleScene.cpp
*@brief �^�C�g���V�[���N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"TitleScene.h"


// �R���X�g���N�^
TitleScene::TitleScene()
{
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
}

// �R���g���[���֐�
SceneID TitleScene::Control()
{
	// ���̃V�[�����i�[����ϐ�
	SceneID nextScene;

	if ((nextScene = m_titleMenu.Control()) != Title_scene)
	{
		return nextScene;
	}

	// �����Ȃ���΃^�C�g����������
	return Title_scene;
}

// �`��֐�
void TitleScene::Draw()
{
	m_titleLogo.Draw();
	m_titleMenu.Draw();
}