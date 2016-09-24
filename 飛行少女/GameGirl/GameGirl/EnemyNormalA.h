/**
*@file EnemyNormalA.h
*@brief エネミーAクラスのヘッダーファイル
*@author　芳我貴之
*2016/08/24制作
*/
#ifndef ENEMY_NORMAL_A_H
#define ENEMY_NORMAL_A_H

#include "Enemy.h"
#include "Effect.h"
#include "WaveEffect.h"

/**敵Aの動くスピード*/
#define ENEMY_A_MOVE_SPEED 3.f

//敵のアニメーションコマ数
#define ENEMY_A_PATTERN 4

/**
*通常敵のAタイプのクラス
*
*/
class EnemyNormalA :public Enemy
{
private:

	/**エフェクトクラス*/
	WaveEffect m_effect;
	

	//敵のアニメパターンカウント数
	int m_animePatternCount;

public:
	
	/**敵クラスAのテクスチャーを格納する変数*/
	static Texture m_enemyATex;

	/**コンストラクタ*/
	EnemyNormalA(D3DXVECTOR2 enemy);
	/**デストラクタ*/
	~EnemyNormalA();

	/**コントロール関数*/
	bool Control();

	/**描画関数*/
	void Draw();

	/**敵の動きを管理する関数*/
	void MoveEnemy();


};

#endif