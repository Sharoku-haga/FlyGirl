/**
*@file WaveEffect.cpp
@brief 波形のエフェクトを扱うクラスのcppファイル
*@autor haga
*/
#include "WaveEffect.h"

Texture WaveEffect::m_waveEffectTex;

/**コンストラクタ*/
WaveEffect::WaveEffect()
{
	//テクチャーを読み込む
	if (WaveEffect::m_waveEffectTex.GetStateTex() == NULL)
	{
		WaveEffect::m_waveEffectTex.GetDevice();
		WaveEffect::m_waveEffectTex.LoadTexEx("Picture\\GameScene\\Effect\\wave01.png", 255, 0, 0, 0, false);
	}
}

/**デストラクタ*/
WaveEffect::~WaveEffect()
{

}

/**描画関数*/
void WaveEffect::Draw()
{
	//波形エフェクトの頂点情報
	CUSTOMVERTEX waveEffect[]
	{
		{ -EFFECT_TEXSIZE / 2.0f, -EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,           0.0f,           0.0f },
		{  EFFECT_TEXSIZE / 2.0f, -EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, WAVE_EFFECT_TU,           0.0f },
		{  EFFECT_TEXSIZE / 2.0f,  EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, WAVE_EFFECT_TU, WAVE_EFFECT_TV },
		{ -EFFECT_TEXSIZE / 2.0f,  EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,           0.0f, WAVE_EFFECT_TV },
	};

	//描画用の空の器
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER;i++)
	{
		drawEffect[i] = waveEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//アニメーションの変化
	if (m_animeCount > 0)
	{
		if (m_animeCount < WAVE_ANIME_PATTERN)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (WAVE_EFFECT_TU * m_animeCount);
			}
		}
		else
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tv += WAVE_EFFECT_TV;
				drawEffect[i].tu += (WAVE_EFFECT_TU  * (m_animeCount - WAVE_ANIME_PATTERN));
			}
		}
	}

	m_animeTime++;

	// 時間に応じて
	if ((m_animeTime % WAVE_ANIME_INTERVAL) == 0)
	{
		if (m_animeCount >= 0)
		{
			if (m_animeCount == ((WAVE_ANIME_PATTERN * 2) - 1))
			{
				m_animeCount = 0;
				m_animeTime = 0;
				m_animeEnd = true;
			}
			else
			{
				m_animeCount++;
			}
		}

	}

	m_waveEffectTex.RenderTex(drawEffect);

}
