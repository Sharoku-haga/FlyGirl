/**
*@file SceneFactory.cpp
*@brief シーンファクトリークラスのcppファイル
*@author　芳我貴之
*
*/
#include"CommonItems.h"
#include"Scene.h"
#include"SceneFactory.h"
#include"LogoScene.h"
#include"TitleScene.h"
#include"GameScene.h"


//シーンIDをもとにシーンを作成
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