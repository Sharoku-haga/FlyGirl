/**
*@file PlayerBullet.cpp
*@brief	プレイヤー弾クラスのcppファイル
*@author　芳我貴之
*2016/08/22制作
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"Bullet.h"
#include"PlayerBullet.h"

//コンストラクタ
PlayerBullet::PlayerBullet(D3DXVECTOR2 player)
{
	m_bulletPos.x = player.x;
	m_bulletPos.y = player.y;
	m_animePattern = 0;

	m_hitFlag = false;
}

//デストラクタ
PlayerBullet::~PlayerBullet()
{

}

//コントロール関数
bool PlayerBullet::Control()
{
	if (m_bulletPos.y < GAMESTAGE_POS_Y)
	{
		m_hitFlag = true;

		return m_hitFlag;
	}

	if (!m_hitFlag)
	{
		m_bulletPos.y -= PLAYER_BULLET_SPEED;
	}
	

	return m_hitFlag;
}

/**描画位置を取得する関数*/
CUSTOMVERTEX* PlayerBullet::GetDrawPos()
{
	//プレイヤー弾の頂点情報
	CUSTOMVERTEX bullet[]
	{
		{ -B_TEXSIZE / 2.0f, -B_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,             0.0f,             0.0f },
		{  B_TEXSIZE / 2.0f, -B_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_BULLET_TU,             0.0f },
		{  B_TEXSIZE / 2.0f,  B_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_BULLET_TU, PLAYER_BULLET_TV },
		{ -B_TEXSIZE / 2.0f,  B_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,             0.0f, PLAYER_BULLET_TV },
	};

	//描画
	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		m_vertex[i] = bullet[i];
		m_vertex[i].x += m_bulletPos.x;
		m_vertex[i].y += m_bulletPos.y;
	}

	//アニメーション
	if (m_animePattern > 0)
	{
		if (m_animePattern < BULLET_ANIME_PATTERN)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				m_vertex[i].tu += (PLAYER_BULLET_TU * m_animePattern);
			}
		}
		else
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				m_vertex[i].tv += PLAYER_BULLET_TV;
				m_vertex[i].tu += (PLAYER_BULLET_TU * (m_animePattern - BULLET_ANIME_PATTERN));
			}
		}
	}

	//アニメーション時間をカウント
	static int bulletAnimeTime = 0;
	bulletAnimeTime++;
	
	if ((bulletAnimeTime % BULLET_ANIME_INTERVAL) == 0)
	{

		if (m_animePattern == ((BULLET_ANIME_PATTERN * 2) - 1))
		{
			m_animePattern = 0;
		}
		else
		{
			m_animePattern++;
		}

	}



	return m_vertex;
}