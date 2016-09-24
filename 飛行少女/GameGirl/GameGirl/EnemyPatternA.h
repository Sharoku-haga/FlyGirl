/**
*@file EnemyPatternA.h
*@brief エネミーパターンAクラスのヘッダーファイル
*@author　芳我貴之
*2016/08/24制作
*/
#ifndef ENEMY_PATTERN_A_H
#define ENEMY_PATTERN_A_H

#include"LibClass.h"
#include "EnemyPattern.h"
#include "EnemyNormalA.h"
#include <list>      
using namespace std;



/**
*エネミーパターンAを管理する
*/
class EnemyPatternA :public EnemyPattern
{
private:
//パターンAにおける敵Aの数
#define ENEMYNORMAL_A_A 2

//敵の出現間隔
#define ENEMY_INTERVAL 20

	//敵Aの出現位置
	D3DXVECTOR2 m_enemyStartPos;
	//敵A
	list<EnemyNormalA> m_enemyNomalA;
	//敵Aのカウント数
	int m_enemyNomalA_Count;

public:

	//コンストラクタ
	EnemyPatternA();
	//デストラクタ
	~EnemyPatternA();

	//コントロール関数
	virtual EnemyPatternID Control();

	//描画関数
	virtual void Draw();
};


#endif
