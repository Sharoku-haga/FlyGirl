/**
*@file Collision.h
*@brief 衝突判定クラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef COLLISION_H
#define COLLISION_H

#include<list>
#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"

using namespace std;
 
//プレイヤーの当たり判定距離
#define COLLSION_PLAYER_RENGE 25

//プレイヤー弾の当たり判定距離
#define COLLSION_BULLET_RENGE 40


//衝突判定用構造体
struct CollisionState
{
	D3DXVECTOR2 pos;			//座標
	bool hitstate;			//当たっているかどうか
};


/**
*衝突判定を行うクラス
*
*/
class Collision
{
private:

	//プレイヤーのステータスを格納する変数
	CollisionState m_playerState;

	//プレイヤー弾のステータスを格納する変数
	list<CollisionState> m_playerBullet;


public:

	//コンストラクタ
	Collision();

	//デストラクタ
	~Collision();

	//実体を習得
	static Collision& GetInstance()
	{
		static Collision collision;

		return collision;
	}

	//プレイヤーのステータスを取得する
	void GetStatePlayer(const D3DXVECTOR2 player);

	//プレイヤーのヒットフラグ初期化
	void InitHitPlayer();

	//プレイヤーが当たっているかをプレイヤーオブジェクトにしらせる
	bool InformHitPlayer();

	//プレイヤーとの衝突チェック
	bool CollisionCheckPlayer(const D3DXVECTOR2* obj);



	//プレイヤー弾のステータスを取得する
	void GetStatePlayer(list<PlayerBullet> &bullet);

	//プレイヤー弾が当たっているかをプレイヤー弾に知らせる
	bool InformHitPlayerBullet(const D3DXVECTOR2* bullet);

	//プレイヤー弾との衝突チェック
	bool CollisionCheckPlayerBullet(const D3DXVECTOR2* obj);


};

#endif