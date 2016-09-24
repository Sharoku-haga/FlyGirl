/**
*@file Scene.h
*@brief シーンクラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef SCENE_H
#define SCENE_H

#include"CommonItems.h"
#include"Score.h"

/**
*シーンクラス
*/
class Scene
{
private:

public:
	/**コンストラクタ*/
	Scene(){};

	/**デストラクタ*/
	virtual ~Scene(){};

	/**コントロール関数*/
	virtual SceneID Control() = 0;
	/**描画関数*/
	virtual void Draw() = 0;

};


#endif	// SCENE_H