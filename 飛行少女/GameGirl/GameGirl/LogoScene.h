/**
*@file LogoScene.h
*@brief ロゴシーンクラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef LOGO_SCENE_H
#define LOGO_SCENE_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"MyLogo.h"

/**
*ロゴシーンを扱うクラス(Sceneクラスの継承クラス)
*
*/
class LogoScene : public Scene
{
private:

	//操作キー
	InputKey m_gameKey;
	//ロゴのクラス
	MyLogo m_myLogo;

public:
	//コンストラクタ
	LogoScene();
	//デストラクタ
	 virtual ~LogoScene();

	//コントロール関数
	virtual SceneID Control();

	//描画関数
	virtual void Draw();

};


#endif // LOGO_SCENE_H