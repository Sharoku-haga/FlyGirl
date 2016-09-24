/**
*@file TitleLogo.cpp
*@brief タイトルロゴ（背景）クラスのcppファイル
*@author　芳我貴之
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"TitleLogo.h"

// コンストラクタ
TitleLogo::TitleLogo()
{
	// テクスチャーを読み込む
	m_titleLogoTex.LoadTex("Picture\\TitleScene\\Title.png");
}

// デストラクタ
TitleLogo::~TitleLogo()
{

}

// 描画関数
void TitleLogo::Draw()
{
	// タイトルロゴの頂点情報
	CUSTOMVERTEX titlelogo[] = {
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	// タイトルロゴを描画
	m_titleLogoTex.RenderTex(titlelogo);
}