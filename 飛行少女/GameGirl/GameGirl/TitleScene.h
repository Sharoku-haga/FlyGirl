/**
*@file TitleScene.h
*@brief タイトルシーンクラスのヘッダファイル
*@author　芳我貴之
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
*タイトルシーンを管理するクラス
*
*/
class TitleScene :public Scene
{
private:
	//タイトルロゴ
	TitleLogo m_titleLogo;

	//タイトルメニュー
	TitleMenu m_titleMenu;

public:
	//コンストラクタ
	TitleScene();
	//デストラクタ
	virtual ~TitleScene();

	//コントロール関数
	virtual SceneID Control();

	//描画関数
	virtual void Draw();
};

#endif	// TITLE_SCENE_H
