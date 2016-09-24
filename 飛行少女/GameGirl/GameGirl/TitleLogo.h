/**
*@file TitleLogo.h
*@brief タイトルロゴ（背景）クラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef TITLE_LOGO_H
#define TITLE_LOGO_H

#include"LibClass.h"
#include"CommonItems.h"

/**
*タイトルロゴ(背景)を管理するクラス<br>
*
*/
class TitleLogo
{
private:

	// タイトルロゴのテクスチャーを格納
	Texture m_titleLogoTex;

public:

	// コンストラクタ
	TitleLogo();

	// デストラクタ
	~TitleLogo();

	// 描画関数
	void Draw();
};



#endif		// TITLE_LOGO_H