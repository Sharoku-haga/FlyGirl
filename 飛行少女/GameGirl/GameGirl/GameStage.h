/**
*@file GameStage.h
*@brief ゲームステージを管理するクラスのヘッダファイル
*@author　芳我貴之
*@data 2016/09/14修正
*/
#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include"LibClass.h"
#include"CommonItems.h"

/**背景のスピード*/
#define BG_MOVESPEED 1.f

/**背景の数*/
enum BackGroud
{
	ONE,
	TWO,
	BG_MAX
};

/**
*ゲームステージ管理クラス
*
*/
class GameStage
{
private:

	/**テクスチャーを格納*/
	Texture m_stageBackground;

	/**背景の座標*/
	D3DXVECTOR2 m_backGround[BG_MAX];

public:
	/**コンストラクタ*/
	GameStage();

	/**デストラクタ*/
	~GameStage();

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

};

#endif	// GAME_STAGE_H