/**
*@file LogoScene.h
*@brief ���S�V�[���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef LOGO_SCENE_H
#define LOGO_SCENE_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"MyLogo.h"

/**
*���S�V�[���������N���X(Scene�N���X�̌p���N���X)
*
*/
class LogoScene : public Scene
{
private:

	//����L�[
	InputKey m_gameKey;
	//���S�̃N���X
	MyLogo m_myLogo;

public:
	//�R���X�g���N�^
	LogoScene();
	//�f�X�g���N�^
	 virtual ~LogoScene();

	//�R���g���[���֐�
	virtual SceneID Control();

	//�`��֐�
	virtual void Draw();

};


#endif // LOGO_SCENE_H