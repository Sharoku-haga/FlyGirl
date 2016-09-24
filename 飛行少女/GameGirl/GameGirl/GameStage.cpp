/**
*@file GameStage.cpp
*@brief ゲームステージを管理するクラスのcppファイル
*@author　芳我貴之
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"GameStage.h"

//コンストラクタ
GameStage::GameStage()
{
	m_stageBackground.LoadTexEx("Picture\\GameScene\\GameStage\\Stage01.png", 255, 0, 0, 0, false);

	//１枚目の背景の初期化
	m_backGround[ONE].x = GAMESTAGE_POS_X;
	m_backGround[ONE].y = GAMESTAGE_POS_Y;


	//２枚目の背景初期化
	m_backGround[TWO].x = GAMESTAGE_POS_X;
	m_backGround[TWO].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);

}

//デストラクタ
GameStage::~GameStage()
{

}

//コントロール関数
void GameStage::Control()
{
	//背景スピード
	m_backGround[ONE].y += BG_MOVESPEED;
	m_backGround[TWO].y += BG_MOVESPEED;


	//画面の下までいくと上にシフトする
	//画面の下までいったら上へシフトする
	if (m_backGround[ONE].y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
	{
		m_backGround[ONE].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);
	}

	if (m_backGround[TWO].y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
	{
		m_backGround[TWO].y = -(GAMESTAGE_H - GAMESTAGE_POS_Y);
	}


}

//描画関数
void GameStage::Draw()
{
	//背景の頂点情報
	CUSTOMVERTEX stage[] = {
		{           0,           0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ GAMESTAGE_W,           0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ GAMESTAGE_W, GAMESTAGE_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{           0, GAMESTAGE_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	//背景1枚目の描画
	CUSTOMVERTEX drawTex01[VERTEX_NUMBER];
	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawTex01[i] = stage[i];

		drawTex01[i].x += m_backGround[ONE].x;
		drawTex01[i].y += m_backGround[ONE].y;

	}
	m_stageBackground.RenderTex(drawTex01);


	//背景２枚目の描画
	CUSTOMVERTEX drawTex02[VERTEX_NUMBER];
	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawTex02[i] = stage[i];

		drawTex02[i].x += m_backGround[TWO].x;
		drawTex02[i].y += m_backGround[TWO].y;

	}
	m_stageBackground.RenderTex(drawTex02);
}