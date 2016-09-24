/**
*@file SceneFactory.cpp
*@brief �V�[���t�@�N�g���[�N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/
#include"CommonItems.h"
#include"Scene.h"
#include"SceneFactory.h"
#include"LogoScene.h"
#include"TitleScene.h"
#include"GameScene.h"


//�V�[��ID�����ƂɃV�[�����쐬
Scene* SceneFactory:: CreateScene(SceneID currentSceneID)
{
	Scene* pScene = nullptr;

	switch (currentSceneID)
	{
	case Logo_scene:

		pScene = new LogoScene();
		break;

	case Title_scene:

		pScene = new TitleScene();
		break;

	case Game_scene:

		pScene = new GameScene();
		break;

	case End_scene:
		break;

	default:
		break;

	}


	return pScene;
}