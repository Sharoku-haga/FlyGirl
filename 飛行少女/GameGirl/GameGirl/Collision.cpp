/**
*@file Collision.cpp
*@brief 衝突判定クラスのcppファイル
*@author　芳我貴之
*
*/

#include "Collision.h"

//コンストラクタ
Collision::Collision()
{
	m_playerState.hitstate = false;
}

//デストラクタ
Collision::~Collision()
{
	m_playerBullet.clear();
}

//プレイヤーのステータスを取得する
void Collision::GetStatePlayer(const D3DXVECTOR2 player)
{
	
		m_playerState.pos.x = player.x;
		m_playerState.pos.y = player.y;
	
}

//プレイヤーのヒットフラグ初期化
void Collision::InitHitPlayer()
{
	m_playerState.hitstate = false;
}

//プレイヤーが当たっているかをプレイヤーオブジェクトにしらせる
bool Collision::InformHitPlayer()
{
	return m_playerState.hitstate;
}


//プレイヤーとの衝突チェック
bool Collision::CollisionCheckPlayer(const D3DXVECTOR2* obj)
{
	//すでに衝突していたらかえす
	if (m_playerState.hitstate)
	{
		return false;
	}
	else
	{
		//当たっていたらtrueをかえす
		if ((abs(obj->y - m_playerState.pos.y)) <= COLLSION_PLAYER_RENGE && (abs(obj->x - m_playerState.pos.x)) <= COLLSION_PLAYER_RENGE)
		{
			m_playerState.hitstate = true;

			return true;
		}
	}

	return false;
}


//プレイヤー弾のステータスを取得する
void Collision::GetStatePlayer(list<PlayerBullet> &bullet)
{
	//取得前に全て初期化する
	if (m_playerBullet.size() > 0)
	{
		m_playerBullet.clear();

	}

	//イテレータを回してデータを取得する
	for (auto itr = bullet.begin(); itr != bullet.end();)
	{
		m_playerBullet.push_back(CollisionState{itr->GetPosBullet(),false});

		itr++;
	}

	return;
}

//プレイヤー弾が当たっているかをプレイヤー弾に知らせる
bool Collision::InformHitPlayerBullet(const D3DXVECTOR2* bullet)
{
	for (auto itr = m_playerBullet.begin(); itr != m_playerBullet.end();)
	{
		//座標で弾を識別する←ここはのちに修正したい
		if (itr->pos.x == bullet->x && itr->pos.y == bullet->y)
		{
			//当たっていれば衝突判定用データを消してtrueを返す
			if (itr->hitstate)
			{
				m_playerBullet.erase(itr);
				return true;
			}
			break;
		}
		else
		{
			itr++;
		}

	}


	return false;
}

//プレイヤー弾との衝突チェック
bool Collision::CollisionCheckPlayerBullet(const D3DXVECTOR2* obj)
{
	for (auto itr = m_playerBullet.begin(); itr != m_playerBullet.end();)
	{
		if (!itr->hitstate)
		{
			//当たっていたらtrueをかえす
			if ((abs(obj->y - itr->pos.y)) <= COLLSION_BULLET_RENGE && (abs(obj->x - itr->pos.x)) <= COLLSION_BULLET_RENGE)
			{
				itr->hitstate = true;

				return true;
			}
		}
	
		itr++;
	}

	return false;
}