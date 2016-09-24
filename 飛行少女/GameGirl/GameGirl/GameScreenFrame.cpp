/**
*@file GameScreenFrame.cpp
*@brief ゲーム画面の枠クラスのcppファイル
*@author　芳我貴之
*2016/08/19描画関数だけ実装
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"GameScreenFrame.h"

//コンストラクタ
GameScreenFrame::GameScreenFrame()
{
	m_screenFarame.LoadTexEx("Picture\\GameScene\\GameScreenFrame\\GameSceneFrame.png",255,0,0,0,false);
}

//デストラクタ
GameScreenFrame::~GameScreenFrame()
{

}

//描画関数
void GameScreenFrame::Draw()
{
	//スクリーンフレームの頂点情報
	CUSTOMVERTEX screenFrame[] = {
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};
	m_screenFarame.RenderTex(screenFrame);
}
