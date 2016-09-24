/**
*@file PlayerBulletManager.cpp
*@brief	プレイヤー弾を管理するクラスのcppファイル
*@author　芳我貴之
*2016/08/22制作
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"
#include"PlayerBulletManager.h"


// コンストラクタ
PlayerBulletManager::PlayerBulletManager()
{
	// テクスチャーを読みこむ
	m_bulletTex_P.LoadTexEx("Picture\\GameScene\\GamePlayer\\PlayerBulletManager\\playerBullet01.png", 255, 0, 0, 0, false);
	m_collision = &Collision::GetInstance();
	m_bulletInterval = 0;

}

// デストラクタ
PlayerBulletManager::~PlayerBulletManager()
{
	// 全要素を削除する
	m_bullet.clear();
}


// コントロール関数
void PlayerBulletManager::Control()
{

	// 衝突判定
	if (m_bullet.size() > 0)
	{
		for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
		{
			if (m_collision->InformHitPlayerBullet(&(itr->GetPosBullet())))
			{
				itr = m_bullet.erase(itr);
			}
			else
			{
				itr++;
			}
		}
	}

	// プレイヤーがヒットしていたらすべて弾を消す
	if (m_collision->InformHitPlayer())
	{
		m_bullet.clear();

		return;
	}
	

	// 弾のコントロール、及び状態確認
	for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
	{
		if (itr->Control())
		{
			itr = m_bullet.erase(itr);
		}
		else
		{
			itr++;
		}
		
	}

	if (m_bullet.size() > 0)
	{
		// 座標を衝突判定に登録する
		m_collision->GetStatePlayer(m_bullet);
	}

	m_bulletInterval++;
	
	if (m_bullet.size() == 0)
	{
		m_bulletInterval = 0;
	}

}


// 描画関数
void PlayerBulletManager::Draw()
{
	// 弾を描画
	for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
	{
		m_bulletTex_P.RenderTex(itr->GetDrawPos());

		itr++;
	}

}

// 弾を作り出す関数
void PlayerBulletManager::CreateBullet(D3DXVECTOR2 player)
{
	if (m_bulletInterval % BULLET_INTEVAL == 0)
	{
		m_bullet.push_back(PlayerBullet(player));
		m_bulletInterval = 0;
	}
	

}
