/**
*@file GameScreenFrame.h
*@brief ゲーム画面の枠クラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef GAME_SCREEN_FARAME_H
#define GAME_SCREEN_FARAME_H

#include"LibClass.h"
#include"CommonItems.h"

/**
*ゲーム画面の枠を管理するクラス<br>
*
*/
class GameScreenFrame
{
private:

	//画像を格納する変数
	Texture m_screenFarame;

public:

	//コンストラクタ
	GameScreenFrame();

	//デストラクタ
	~GameScreenFrame();

	//描画関数
	void Draw();

};





#endif