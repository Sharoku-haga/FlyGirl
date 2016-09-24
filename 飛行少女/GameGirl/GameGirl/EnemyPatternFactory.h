/**
*@file EnemyPatternFactory.h
*@brief エネミーパターンファクトリークラスのヘッダーファイル
*@author　芳我貴之
*2016/08/23制作
*/
#ifndef ENEMY_PATTERN_FACTORY_H
#define ENEMY_PATTERN_FACTORY_H

#include"CommonItems.h"
#include "EnemyPattern.h"
#include "EnemyPatternA.h"

/**
*敵パターンの生成を行うクラス
*/
class EnemyPatternFactory
{
public:
	//コンストラクタ
	EnemyPatternFactory(){};
	//デストラクタ
	~EnemyPatternFactory(){};

	//実体化（別にstaticではなく、普通にEnemyPatternManagerにもたせるのも１つの案）
	static EnemyPatternFactory& Instance()
	{
		static EnemyPatternFactory enemyPatternFactory;

		return enemyPatternFactory;
	}

	//敵のパターンを作成
	EnemyPattern* CreateEnemyPattern(EnemyPatternID enemyPattern);

};


#endif