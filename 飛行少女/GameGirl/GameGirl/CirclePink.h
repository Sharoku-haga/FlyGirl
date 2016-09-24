/**
*@file CirclePink.h
*@brief ピンクの円のエフェクトクラスのヘッダーファイル
*@author haga
*@data 2016/09/14
*/
#ifndef CIRCLE_PINK_H
#define CIRCLE_PINK_H

/**サークルのアニメ間隔*/
#define CIRCLE_P_INTERVAL 2

/**サークルエフェクトサイズ*/
#define CIRCLE_P_TEXSIZE 180.f

#include "Effect.h"

/**
*ピンクの円のエフェクトクラス(プレイヤーがヒットしたときのエフェクト)<br>
*
*/
class CirclePink :public Effect
{
private:

	/**エフェクトテクスチャー*/
	static Texture m_circleEffectTex;

public:
	/**コンストラクタ*/
	CirclePink();

	/**デストラクタ*/
	virtual~CirclePink();

	/**描画関数*/
	virtual void Draw();
};

#endif // CIRCLE_PINK_H