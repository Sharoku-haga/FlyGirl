/**
*@file PlayerBullet.h
*@brief	プレイヤー弾クラスのヘッダファイル
*@author　芳我貴之
*2016/08/22制作
*/
#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include"LibClass.h"
#include"Bullet.h"

/**プレイヤー弾の移動速度*/
#define PLAYER_BULLET_SPEED 15.f

/**プレイヤー弾のtu値*/
#define PLAYER_BULLET_TU 0.2f
/**プレイヤー弾のtv値*/
#define PLAYER_BULLET_TV 0.5f
/**プレイヤー弾アニメーションパターン数*/
#define BULLET_ANIME_PATTERN 5
/**プレイヤー弾アニメーション間隔*/
#define BULLET_ANIME_INTERVAL 1

/**
*プレイヤー弾クラス
*
*/
class PlayerBullet :public Bullet
{
private:

	/**プレイヤー弾のアニメパターン数*/
	int m_animePattern;

public:
	//コンストラクタ
	PlayerBullet(D3DXVECTOR2 player);
	//デストラクタ
	~PlayerBullet();


	//弾の座標を取得する関数
	D3DXVECTOR2 GetPosBullet(){ return m_bulletPos; }

	//コントロール関数
	virtual bool Control();

	/**描画位置を取得する関数*/
	virtual CUSTOMVERTEX* GetDrawPos();

};




#endif