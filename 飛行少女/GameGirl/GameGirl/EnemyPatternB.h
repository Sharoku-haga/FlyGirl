/**
*@file EnemyNormalB.cpp
*@brief エネミーBクラスのcppファイル
*@author　芳我貴之
*2016/08/24制作
*/
#ifndef ENEMY_PATTERN_B_H
#define ENEMY_PATTERN_B_H

#include"LibClass.h"
#include "EnemyPattern.h"
#include "EnemyNormalA.h"
#include <list>      
using namespace std;


class EnemyPatternB :public EnemyPattern
{
private:
	//敵の数
#define ENEMYNORMAL_A 10

	//敵の出現間隔
#define ENEMY_INTERVAL 20

	//敵Aの出現位置
	D3DXVECTOR2 m_enemyStartPos;
	//敵A
	list<EnemyNormalA> m_enemyNomalA;
	//敵Aのカウント数
	int m_enemyNomalA_Count;

public:

	EnemyPatternB();

	~EnemyPatternB();

	//コントロール関数
	virtual EnemyPatternID Control();

	//描画関数
	virtual void Draw();
};

#endif