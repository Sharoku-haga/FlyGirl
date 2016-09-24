/**
*@file TitleScene.h
*@brief �^�C�g���V�[���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/19 
*/
#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"TitleLogo.h"
#include"TitleMenu.h"
/**
*�^�C�g���V�[�����Ǘ�����N���X
*
*/
class TitleScene :public Scene
{
private:
	//�^�C�g�����S
	TitleLogo m_titleLogo;

	//�^�C�g�����j���[
	TitleMenu m_titleMenu;

public:
	//�R���X�g���N�^
	TitleScene();
	//�f�X�g���N�^
	virtual ~TitleScene();

	//�R���g���[���֐�
	virtual SceneID Control();

	//�`��֐�
	virtual void Draw();
};

#endif	// TITLE_SCENE_H
