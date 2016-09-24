/**
*@file LogoScene.h
*@brief ���S�V�[���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"LogoScene.h"
#include"MyLogo.h"

//�R���X�g���N�^
LogoScene::LogoScene()
{
	
}

//�f�X�g���N�^
LogoScene::~LogoScene()
{

}

//�R���g���[���֐�
SceneID LogoScene::Control()
{
	m_gameKey.UpdateKey();

	//�L�[��Ԃ��m�F
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);

	//�{�^���������ꂽ��^�C�g���V�[���Ɉڍs����
	if (m_gameKey.m_Key[Z] == ON)
	{
		return SceneID::Title_scene;
	}

	return Logo_scene;
}

//�`��֐�
void LogoScene::Draw()
{
	m_myLogo.Draw();
}