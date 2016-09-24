/**
*@file Effect.h
*@brief エフェクトの基本クラス(抽象クラス)
*@autor haga
*
*/
#ifndef EFFECT_H
#define EFFECT_H

/**エフェクトのテクスチャーサイズ*/
#define EFFECT_TEXSIZE 128.f

#include"CommonItems.h"
#include"Texture.h"

/**
*エフェクトのクラス.
*
*/
class Effect
{

protected:

	/**効果の座標*/
	D3DXVECTOR2 m_effctPos;

	/**アニメーション終了のフラグ*/
	bool m_animeEnd;

	/**アニメーション時間*/
	int m_animeTime;

	/**アニメーションのパターンをカウントする変数*/
	int m_animeCount;

	/*アニメーションの数を格納する変数**/
	int m_animeNumber;

public:

	/**コンストラクタ*/
	Effect()
	{
		m_animeNumber = 0;
		m_animeEnd = false;
		m_animeTime = 0;
		m_animeCount = 0;
	};

	/**デストラクタ*/
	virtual~Effect(){};

	/**描画関数*/
	virtual void Draw(){};

	/**アニメーションの状態を確認*/
	bool GetAnimeState()
	{ 
		if (m_animeEnd)
		{
			m_animeEnd = false;
			
			return true;
		}
		else
		{
			return false;
		}
	};

	/**座標をセットする*/
	void SetEffectPos(D3DXVECTOR2 _objPos){ m_effctPos = _objPos; }
};

#endif