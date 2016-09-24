/**
*@file RotheCircle.h
*@brief 回転する円のエフェクトクラスのcpp
*
*/
#include "RotheCircle.h"

Texture RotheCircle::m_rotheCircleTex;

// コンストラクタ
RotheCircle::RotheCircle()
{
	//  テクスチャー読み込み
	if (RotheCircle::m_rotheCircleTex.GetStateTex() == NULL)
	{
		RotheCircle::m_rotheCircleTex.GetDevice();
		RotheCircle::m_rotheCircleTex.LoadTexEx("Picture\\GameScene\\Effect\\rotation01.png", 255, 0, 0, 0, false);
	}
}

// デストラクタ
RotheCircle::~RotheCircle()
{
}

// 描画関数
void RotheCircle::Draw()
{
	// 回転エフェクトの頂点情報
	CUSTOMVERTEX rotheCircleEffect[]
	{
		{ -ROTHE_TEXSIZE / 2.0f, -ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 0.0f },
		{  ROTHE_TEXSIZE / 2.0f, -ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.2f, 0.0f },
		{  ROTHE_TEXSIZE / 2.0f,  ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.2f, 1.0f },
		{ -ROTHE_TEXSIZE / 2.0f,  ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 1.0f },
	};

	// 描画用の空の器
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawEffect[i] = rotheCircleEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//アニメーションの変化
	if (m_animeCount > 0)
	{
		// 4はアニメパターンの数
		if (m_animeCount <= 4)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (0.2f * m_animeCount);
			}
		}
	}

	m_animeTime++;

	// 時間に応じて
	if ((m_animeTime % ROTHE_ANIME_INTERVAL) == 0)
	{
		if (m_animeCount >= 0)
		{
			if (m_animeCount == 4)
			{
				m_animeCount = 0;
				m_animeTime = 0;
				
				if (m_animeNumber == 4)
				{
					m_animeEnd = true;
					m_animeNumber = 0;
				}
				
				m_animeNumber++;
			}
			else
			{
				m_animeCount++;
			}
		}
	}

	m_rotheCircleTex.RenderTex(drawEffect);
}
