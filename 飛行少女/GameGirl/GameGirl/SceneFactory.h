/**
*@file SceneFactory.h
*@brief シーンファクトリークラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H

#include"CommonItems.h"
#include"Scene.h"
/**
*SceneFactoryクラス<br>
*SceneIDに応じてシーンを実体化させる
*
*/
class SceneFactory
{
private:

public:
	//コンストラクタ
	SceneFactory(){};
	//デストラクタ
	~SceneFactory(){};

	//実体化
	static SceneFactory& Instance()
	{
		static SceneFactory sceneFactory;

		return sceneFactory;
	}

	//シーンIDをもとにシーンを作成
	Scene* CreateScene(SceneID currentSceneID);
};



#endif