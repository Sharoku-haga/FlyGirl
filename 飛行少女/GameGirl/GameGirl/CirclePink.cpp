/**
*@file CirclePink.cpp 
*@brief ピンクの円のエフェクトクラス
*
*/
#include "CirclePink.h"

// static関数
Texture CirclePink::m_circleEffectTex;

// コンストラクタ
CirclePink::CirclePink()
{
	//テクチャーを読み込む
	if (CirclePink::m_circleEffectTex.GetStateTex() == NULL)
	{
		CirclePink::m_circleEffectTex.GetDevice();
		CirclePink::m_circleEffectTex.LoadTexEx("Picture\\GameScene\\Effect\\CirclePink.png", 255, 0, 0, 0, false);
	}
}

// デストラクタ
CirclePink::~CirclePink()
{
}

// 描画関数
void CirclePink::Draw()
{
	//波形エフェクトの頂点情報
	CUSTOMVERTEX circleEffect[]
	{
		{ -CIRCLE_P_TEXSIZE / 2.0f, -CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  CIRCLE_P_TEXSIZE / 2.0f, -CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.0f },
		{  CIRCLE_P_TEXSIZE / 2.0f,  CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 1.0f },
		{ -CIRCLE_P_TEXSIZE / 2.0f,  CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// 描画用の空の器
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawEffect[i] = circleEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//アニメーションの変化
	if (m_animeCount > 0)
	{
		// 4はアニメパターンの数
		if (m_animeCount <= 4 )
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (0.2f * m_animeCount);
			}
		}
	}

	m_animeTime++;

	// 時間に応じて
	if ((m_animeTime % CIRCLE_P_INTERVAL) == 0)
		{
			if (m_animeCount >= 0)
			{
				if (m_animeCount == 4)
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

	m_circleEffectTex.RenderTex(drawEffect);
	
}
