/**
*@file GamePlayer.cpp
*@brief ゲームプレイヤークラスのcppファイル
*@author　芳我貴之
*2016/08/20制作
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"GamePlayer.h"
#include"PlayerBulletManager.h"

//コンストラクタ
GamePlayer::GamePlayer()
{
	m_playerTex.LoadTexEx("Picture\\GameScene\\GamePlayer\\Player.png", 255, 0, 0, 0, false);
	m_slowModeTex.LoadTexEx("Picture\\GameScene\\GamePlayer\\center16.png", 255, 0, 0, 0, false);
	m_playerPos.x = P_POSX_INITVAL;
	m_playerPos.y = P_POSY_INITVAL;
	m_moveSpeed = P_MOVE_SPEED_DEFAULT;
	m_collision = &Collision::GetInstance();
	m_playerLife = LIFE_INITVAL;
	m_animePattern = 0;
	m_animeReverse = false;
	m_playerState = NORMAL;
}

//デストラクタ
GamePlayer::~GamePlayer()
{
}

// コントロール関数
bool GamePlayer::Control()
{
	// 衝突しているかを確認
	if (m_collision->InformHitPlayer())
	{
		m_effectManager.SetHitEffectPos(&m_playerPos);
		m_playerState = HIT;
		
	}

	if (m_effectManager.GetStateInviEffect())
	{
		m_playerState = NORMAL;
	}

	// 当たっていなければキー操作が行える
	if (m_playerState != HIT)
	{
		KeyControl();	
	}
	else
	{
		// エフェクトが終わったら
		if (m_effectManager.GetStateHitEffect())
		{
			// ここでHPをへらしている
			// m_playerLife -= 1;

			if (m_playerLife >= 0)
			{
				//エフェクト終了後
				m_playerState = INVINCIBLE;
				//衝突判定のフラグをもとにもどす
				m_collision->InitHitPlayer();
				//初期位置へ戻す
				m_playerPos.x = P_POSX_INITVAL;
				m_playerPos.y = P_POSY_INITVAL;
			}
			else
			{
				// ライフが0ならtrueかえす
				return true;
			}
		}
		
	}

	//当たっていなければ座標をわたす
	if (m_playerState != HIT)
	{
		// 無敵状態中は衝突判定に｛0,0｝の座標をわたす
		if (m_playerState == INVINCIBLE)
		{
			D3DXVECTOR2 invinciblePos = {0,0};
			m_collision->GetStatePlayer(invinciblePos);
		}
		else
		{
			m_collision->GetStatePlayer(m_playerPos);
		}
	}
	m_playerBulletManager.Control();

	return false;
}


// 描画関数
void GamePlayer::Draw()
{

	//当たってなければ通常描画
	if (m_playerState != HIT)
	{
		//弾の描画
		m_playerBulletManager.Draw();

		DrawNormal();

		if (m_moveSpeed == P_MOVE_SPEED_SHIFT)
		{
			// 低速モードなら点を描画
			DrawSlowMode();
		}

		if (m_playerState == INVINCIBLE)
		{
			m_effectManager.DrawInviEffect(&m_playerPos);
		}

	}
	else
	{
		// ヒットエフェクトを描画
		m_effectManager.DrawHitEffect();
	}

}


//コントロールキー操作
void GamePlayer::KeyControl()
{
	
	m_gameKey.UpdateKey();

	// キー状態を確認
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_UP], UP);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_DOWN], DOWN);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_RIGHT], RIGHT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LEFT], LEFT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LSHIFT], SHIFT);

	// shiftを押すと低速モードに切り替わる
	if (m_gameKey.m_Key[SHIFT] == ON)
	{
		m_moveSpeed = P_MOVE_SPEED_SHIFT;
	}
	else
	{
		m_moveSpeed = P_MOVE_SPEED_DEFAULT;
	}

	if (m_gameKey.m_Key[UP] == ON)
	{
		if (m_playerPos.y >= (GAMESTAGE_POS_Y + PLAYER_RANGE))
		{
			m_playerPos.y -= m_moveSpeed;
		}

	}
	if (m_gameKey.m_Key[DOWN] == ON)
	{
		if (m_playerPos.y <= (GAMESTAGE_H + GAMESTAGE_POS_Y - PLAYER_RANGE))
		{
			m_playerPos.y += m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[RIGHT] == ON)
	{
		if (m_playerPos.x <= (GAMESTAGE_W + GAMESTAGE_POS_X - PLAYER_RANGE))
		{
			m_playerPos.x += m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[LEFT] == ON)
	{
		if (m_playerPos.x >= GAMESTAGE_POS_X + PLAYER_RANGE)
		{
			m_playerPos.x -= m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[Z] == PUSH || m_gameKey.m_Key[Z] == ON)
	{
		// 弾発射
		m_playerBulletManager.CreateBullet(m_playerPos);
	
	}

}

// プレイヤーを描画する関数
void GamePlayer::DrawNormal()
{
	// プレイヤーの頂点情報
	CUSTOMVERTEX player[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,          0.0f,          0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_TEX_TU,          0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_TEX_TU, PLAYER_TEX_TV },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,          0.0f, PLAYER_TEX_TV },
	};

	//描画用の変数
	CUSTOMVERTEX drawPlayer[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawPlayer[i] = player[i];

		drawPlayer[i].x += m_playerPos.x;
		drawPlayer[i].y += m_playerPos.y;

	}

	if (m_animePattern != 0)
	{
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			drawPlayer[i].tu += (PLAYER_TEX_TU * m_animePattern);
		}

	}

	//アニメーション時間をカウント
	static int playerAnimeTime = 0;
	playerAnimeTime++;

	if ((playerAnimeTime % PLAYER_ANIME_INTERVAL) == 0)
	{
		if (!m_animeReverse)
		{
			m_animePattern++;

			if (m_animePattern == PLAYER_ANIME_PATTERN)
			{
				m_animeReverse = true;
			}
		}
		else
		{
			m_animePattern--;
			if (m_animePattern == 0)
			{
				m_animeReverse = false;
				playerAnimeTime = 0;
			}
		}

	}

	if (m_playerState == INVINCIBLE)
	{
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			drawPlayer[i].color = 0x99FFFFFF;
		}
	}

	m_playerTex.RenderTex(drawPlayer);

}

// 低速モードにおける画像を描画する関数
void GamePlayer::DrawSlowMode()
{
	//低速モードにおける点の頂点情報
	CUSTOMVERTEX slowPoint[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//描画用の変数
	CUSTOMVERTEX drawPoint[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawPoint[i] = slowPoint[i];

		drawPoint[i].x += m_playerPos.x;
		drawPoint[i].y += m_playerPos.y;
	}

	m_slowModeTex.RenderTex(drawPoint);
}