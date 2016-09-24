/**
*@file Bullet.h
*@brief 弾クラスのヘッダファイル
*@author　芳我貴之
*2016/08/22制作
*/
#ifndef BULLET_H
#define BULLET_H

#include"LibClass.h"
#include"CommonItems.h"

/**弾のテクスチャーサイズ*/
#define B_TEXSIZE 64.f

/**
*弾の基本クラス
*
*/
class Bullet
{
protected:

	/*弾の位置*/
	D3DXVECTOR2 m_bulletPos;

	/*描画フラグ*/
	bool m_hitFlag;

	/**バーテックス情報*/
	CUSTOMVERTEX m_vertex[VERTEX_NUMBER];

public:
	//コンストラクタ
	Bullet(){};
	//デストラクタ
	virtual ~Bullet(){};

	/**これより下の仮想関数は弾のふるまいを流動的にかえる場合を想定して実装しておく*/

	/**コントロール関数*/
	virtual bool Control() = 0;

	/**描画位置を取得する関数*/
	virtual CUSTOMVERTEX* GetDrawPos() = 0;


};


#endif