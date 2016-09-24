/**
*@file RotheCircle.h
*@brief 回転する円のエフェクトクラスのヘッダーファイル
*@author haga
*@data 2016/09/16
*
*/
#ifndef ROTHE_CIRCLE_H
#define ROTHE_CIRCLE_H

/**回転エフェクトのテクスチャーサイズ*/
#define ROTHE_TEXSIZE 108.f
/**回転のエフェクトのアニメ間隔*/
#define ROTHE_ANIME_INTERVAL 5

#include "Effect.h"
class RotheCircle :public Effect
{
private:
	/**テクスチャーを格納する変数*/
	static Texture m_rotheCircleTex;
	
public:
	/**コンストラクタ*/
	RotheCircle();

	/**デストラクタ*/
	~RotheCircle();

	/**描画関数*/
	virtual void Draw();
};

#endif	// ROTHE_CIRCLE_H
