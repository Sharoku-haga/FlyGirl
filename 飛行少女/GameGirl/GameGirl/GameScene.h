/**
*@file GameScene.h
*@brief ゲームシーンクラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"GameScreenFrame.h"
#include"GameStage.h"
#include"GamePlayer.h"
#include "EnemyPatternManager.h"
/**
*ゲームシーンを管理するクラス<br>
*
*/
class GameScene : public Scene
{
private:

	//画面の枠クラス
	GameScreenFrame m_screenFrame;

	//ゲームステージ(背景)クラス
	GameStage m_gameStage;

	//ゲームプレイヤークラス
	GamePlayer m_gamePlayer;

	//敵のパターンを管理するクラス
	EnemyPatternManager m_enemyPatternManager;

public:
	//コンストラクタ
	GameScene();

	//デストラクタ
	virtual ~GameScene();

	//コントロール関数
	virtual SceneID Control();

	//描画関数
	virtual void Draw();

};


#endif