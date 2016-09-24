/**
*@file WaveEffect.h
@brief 波形のエフェクトを扱うクラスのヘッダーファイル
*@autor haga
*/
#ifndef WAVE_EFFECT_H
#define WAVE_EFFECT_H

/**波形にエフェクトのtu値*/
#define WAVE_EFFECT_TU 0.2f
/**波形にエフェクトのtv値*/
#define WAVE_EFFECT_TV 0.5f

/**波形のエフェクトのアニメパターン１列目の数*/
#define WAVE_ANIME_PATTERN 5

/**波形のエフェクトのアニメ時間*/
#define WAVE_ANIME_INTERVAL 1

#include "Effect.h"

/**
*円型の波形のエフェクトを扱うクラス
*
*/
class WaveEffect :public Effect
{
private:

	/**tテクスチャーを格納する変数*/
	static Texture m_waveEffectTex;

public:

	/**コンストラクタ*/
	WaveEffect();
	/**デストラクタ*/
	virtual~WaveEffect();

	/**描画関数*/
	virtual void Draw();

};


#endif
