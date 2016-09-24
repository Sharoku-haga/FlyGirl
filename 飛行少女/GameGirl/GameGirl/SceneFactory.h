/**
*@file SceneFactory.h
*@brief �V�[���t�@�N�g���[�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H

#include"CommonItems.h"
#include"Scene.h"
/**
*SceneFactory�N���X<br>
*SceneID�ɉ����ăV�[�������̉�������
*
*/
class SceneFactory
{
private:

public:
	//�R���X�g���N�^
	SceneFactory(){};
	//�f�X�g���N�^
	~SceneFactory(){};

	//���̉�
	static SceneFactory& Instance()
	{
		static SceneFactory sceneFactory;

		return sceneFactory;
	}

	//�V�[��ID�����ƂɃV�[�����쐬
	Scene* CreateScene(SceneID currentSceneID);
};



#endif