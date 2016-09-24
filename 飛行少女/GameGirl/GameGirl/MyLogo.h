/**
*@file MyLogo.h
*@brief ロゴのコントロールや描画を管理するクラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef MY_LOGO_H
#define MY_LOGO_H

#include"LibClass.h"


/**
*ロゴの描画やコントロールを管理するクラス
*
*/
class MyLogo
{
private:
	//ロゴシーンのテクスチャを管理
	Texture m_Logo;

public:
	//コンストラクタ
	MyLogo();
	//デストラクタ
	~MyLogo();

	//描画関数
	void Draw();
};



#endif