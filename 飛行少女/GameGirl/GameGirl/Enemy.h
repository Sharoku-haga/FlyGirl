/**
*@file Enemy.h
*@brief エネミークラスのヘッダーファイル
*@author　芳我貴之
*2016/08/24制作
*/
#ifndef ENEMY_H
#define ENEMY_H

#include"LibClass.h"
#include"CommonItems.h"
#include "Collision.h"

/**敵の動き方を示すID*/
enum EnmeyMoveType
{
	RightMove,		//右に動く
	LeftMove,		//左に動く
	NormalMove		//下に動く
};

/**敵画像のtu値*/
#define ENEMY_TEX_TU 0.083f
/**敵画像のtu値*/
#define ENEMY_TEX_TV 0.25f


/**
*敵のクラス
*
*/
class Enemy
{

protected:

	//敵の位置座標
	D3DXVECTOR2 m_enemyPos;

	//敵の初期位置を示す変数
	EnmeyMoveType m_enemyMoveType;

	/**衝突判定*/
	Collision* m_collision;

	/**初期化フラグ*/
	bool m_initFlag;

	/**当たりフラグ*/
	bool m_hitFlag;

	/**t敵の終了フラグ*/
	bool m_endFlag;

	/**バーテックス情報*/
	CUSTOMVERTEX m_vertex[VERTEX_NUMBER];


public:

	Enemy()
	{
		m_collision = &Collision::GetInstance();
		m_endFlag = false;

		m_hitFlag = false;
		m_initFlag = true;
	};
	virtual~Enemy(){};

	/**座標を取得する関数*/
	D3DXVECTOR2 GetPos(){ return m_enemyPos; }

	/**描画位置を取得する関数*/
	CUSTOMVERTEX* GetDrawPos(){ return m_vertex; };

	/**これより下の仮想関数は弾のふるまいを流動的にかえる場合を想定して実装しておく*/

	/**コントロール関数*/
	virtual bool Control() = 0;

	/**描画関数*/
	virtual void Draw() = 0;

};



#endif