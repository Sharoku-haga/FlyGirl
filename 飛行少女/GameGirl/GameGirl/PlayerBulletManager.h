/**
*@file PlayerBulletManager.h
*@brief	プレイヤー弾を管理するクラスのヘッダファイル
*@author　芳我貴之
*2016/08/22制作
*/
#ifndef PLAYER_BULLET_MANAGER_H
#define PLAYER_BULLET_MANAGER_H

#include<list>
#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"
#include "Collision.h"

using namespace std;

/**弾の間隔*/
#define BULLET_INTEVAL 5

/**
*プレイヤー弾の数、及び描画を管理するクラス
*/
class PlayerBulletManager
{
private:

	/**プレイヤーのテクチャーを格納する変数*/
	Texture m_bulletTex_P;

	/**リスト構造のバレット*/
	list<PlayerBullet> m_bullet;

	/**弾の連射における間隔*/
	int m_bulletInterval;

	/**衝突判定*/
	Collision* m_collision;

public:

	/**コンストタクタ*/
	PlayerBulletManager();

	/**デストラクタ*/
	~PlayerBulletManager();

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

	/**
	*弾を作り出す関数<br>
	*param[in] player プレイヤーの現在の座標
	*
	*/
	void CreateBullet(D3DXVECTOR2 player);




};


#endif