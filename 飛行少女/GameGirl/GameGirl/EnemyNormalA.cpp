/**
*@file EnemyNormalA.cpp
*@brief エネミーAクラスのcppファイル
*@author　芳我貴之
*2016/08/24制作
*/
#include"Commonitems.h"
#include "EnemyNormalA.h"

Texture EnemyNormalA::m_enemyATex ;


/**コンストラクタ*/
EnemyNormalA::EnemyNormalA(D3DXVECTOR2 enemy)
{
	m_enemyPos.x = enemy.x;
	m_enemyPos.y = enemy.y;

	m_enemyMoveType = NormalMove;

	m_animePatternCount = 0;

	if (EnemyNormalA::m_enemyATex.GetStateTex() == NULL)
	{
		EnemyNormalA::m_enemyATex.GetDevice();
		EnemyNormalA::m_enemyATex.LoadTexEx("Picture\\GameScene\\EnemyPatternManager\\th_kedama2.png", 255, 0, 0, 0, false);
	}
	
}


/**デストラクタ*/
EnemyNormalA::~EnemyNormalA()
{
	
}

/**コントロール関数*/
bool EnemyNormalA::Control()
{
	//初期の座標で動き方を変更させる
	if (m_initFlag)
	{
		if (m_enemyPos.x <= GAMESTAGE_POS_X)
		{
			m_enemyMoveType = RightMove;
		}
		else if (m_enemyPos.x >= (GAMESTAGE_POS_X + GAMESTAGE_W))
		{
			m_enemyMoveType = LeftMove;
		}
		else
		{
			m_enemyMoveType = NormalMove;
		}

		m_initFlag = false;
	}

	//衝突判定
	if (!m_hitFlag)
	{
		//プレイヤーとの衝突判定を行う
		m_collision->CollisionCheckPlayer(&m_enemyPos);

		//プレイヤー弾との衝突判定を行う
		if (m_collision->CollisionCheckPlayerBullet(&m_enemyPos))
		{
			m_hitFlag = true;
			m_effect.SetEffectPos(m_enemyPos);
		
		}
	}


	if (!m_hitFlag)
	{
		MoveEnemy();
	}
	else
	{
		//エフェクトのアニメーションが終われば終了フラグをたてる
		if (m_effect.GetAnimeState())
		{
			m_endFlag = true;
		}
	}

	return m_endFlag;
}

/**描画関数*/
void EnemyNormalA::Draw()
{
	if (!m_hitFlag)
	{
		//敵Aの頂点情報
		CUSTOMVERTEX enemynomalA[] =
		{
			{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,         0.0f,         0.0f },
			{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, ENEMY_TEX_TU,         0.0f },
			{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, ENEMY_TEX_TU, ENEMY_TEX_TV },
			{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,         0.0f, ENEMY_TEX_TV },
		};

		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			m_vertex[i] = enemynomalA[i];

			m_vertex[i].x += m_enemyPos.x;
			m_vertex[i].y += m_enemyPos.y;
		}

		//アニメーションパターンにあわせてtv値を変化
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			m_vertex[i].tv += (ENEMY_TEX_TV * m_animePatternCount);
		}

		if (m_animePatternCount < ENEMY_A_PATTERN)
		{
			m_animePatternCount++;
		}
		else
		{
			m_animePatternCount = 0;
		}

		EnemyNormalA::m_enemyATex.RenderTex(m_vertex);
	}
	else
	{
		m_effect.Draw();
	}
}


/**敵の動きを管理する関数*/
void EnemyNormalA::MoveEnemy()
{
	//IDによって動くパターンを変える
	switch (m_enemyMoveType)
	{
	case LeftMove:
		m_enemyPos.x -= ENEMY_A_MOVE_SPEED;
		

		if (m_enemyPos.x <= GAMESTAGE_POS_X)
		{
			m_hitFlag = true;
			m_endFlag = true;
		}

		break;

	case RightMove:
		m_enemyPos.x += ENEMY_A_MOVE_SPEED;
		

		if (m_enemyPos.x >= (GAMESTAGE_POS_X + GAMESTAGE_W))
		{
			m_hitFlag = true;
			m_endFlag = true;
		}
		break;

	case NormalMove:

		m_enemyPos.y += ENEMY_A_MOVE_SPEED;
		if (m_enemyPos.y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
		{
			m_hitFlag = true;
			m_endFlag = true;
		}

		break;

	};
}