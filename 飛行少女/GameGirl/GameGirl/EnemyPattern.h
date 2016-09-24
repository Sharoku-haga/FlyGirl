/**
*@file EnemyPattern.h
*@brief エネミーパターンクラスのヘッダーファイル
*@author　芳我貴之
*2016/08/24制作
*/
#ifndef ENEMY_PATTERN_H
#define ENEMY_PATTERN_H

#include"CommonItems.h"

/**
*敵のパターンの基底クラス
*
*/
class EnemyPattern
{
private:

public:

	//コンストラクタ
	EnemyPattern(){};

	//デストラクタ
	virtual ~EnemyPattern(){};

	//コントロール関数
	virtual EnemyPatternID Control() = 0;

	//描画関数
	virtual void Draw() = 0;
};

#endif