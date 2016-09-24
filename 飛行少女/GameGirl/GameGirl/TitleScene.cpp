/**
*@file TitleScene.cpp
*@brief タイトルシーンクラスのcppファイル
*@author　芳我貴之
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"TitleScene.h"


// コンストラクタ
TitleScene::TitleScene()
{
}

// デストラクタ
TitleScene::~TitleScene()
{
}

// コントロール関数
SceneID TitleScene::Control()
{
	// 次のシーンを格納する変数
	SceneID nextScene;

	if ((nextScene = m_titleMenu.Control()) != Title_scene)
	{
		return nextScene;
	}

	// 何もなければタイトルをかえす
	return Title_scene;
}

// 描画関数
void TitleScene::Draw()
{
	m_titleLogo.Draw();
	m_titleMenu.Draw();
}