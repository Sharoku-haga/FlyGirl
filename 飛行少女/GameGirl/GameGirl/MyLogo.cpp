/**
*@file MyLogo.cpp
*@brief ロゴのコントロールや描画を管理するクラスのcppファイル
*@author　芳我貴之
*
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"MyLogo.h"


//コンストラクタ
MyLogo::MyLogo()
{
	//ロゴのテクスチャーを読み込む
	m_Logo.LoadTexEx("Picture\\LogoScene\\MyLogo.png",255,0,0,0,false);
	//ロゴのテクスチャーを読み込む
	//m_Logo.LoadTexEx("val.jpg",255,0,0,0,true);
	//m_Logo.LoadTex("val.jpg");
}

//デストラクタ
MyLogo::~MyLogo()
{

}

//ロゴの描画
void MyLogo::Draw()
{
	
	//ロゴの頂点情報
	CUSTOMVERTEX logo[] ={
		{        0,        0, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ WINDOW_W,        0, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ WINDOW_W, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{        0, WINDOW_H, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f }

	};

	//描画
	m_Logo.RenderTex(logo);
	
}


