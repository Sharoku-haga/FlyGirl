/**
*@file GameScene.cpp
*@brief ゲームシーンクラスのcppファイル
*@author　芳我貴之
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"GameScene.h"

// コンストラクタ
GameScene::GameScene()
{

}

// デストラクタ
GameScene::~GameScene()
{

}


// コントロール関数
SceneID GameScene::Control()
{
	// 背景のコントロール
	m_gameStage.Control();

	
	// 敵のパターンマネージャー(敵のパターン全てが終わったらシーンを終了する)
	if (m_enemyPatternManager.Control())
	{
		return Title_scene;
	}
	
	// プレイヤーコントロール(死亡フラグがたっていたらシーンを終了する)
	if (m_gamePlayer.Control())
	{
		return Title_scene;
	}

	return Game_scene;
}


// 描画関数
void GameScene::Draw()
{
	// 背景の描画
	m_gameStage.Draw();
	
	// プレイヤーの描画
	m_gamePlayer.Draw();

	// 敵の描画
	m_enemyPatternManager.Draw();;

	// 画面枠の描画
	m_screenFrame.Draw();
}