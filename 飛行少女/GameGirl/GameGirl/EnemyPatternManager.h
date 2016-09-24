/**
*@file EnemyPatternManager.h
*@brief エネミーパターンマネージャークラスのヘッダーファイル
*@author　芳我貴之
*2016/08/23制作
*/
#ifndef ENEMY_PATTERN_MANAGER_H
#define ENEMY_PATTERN_MANAGER_H

#include"CommonItems.h"
#include "EnemyPatternFactory.h"
#include "EnemyPattern.h"
/**
*敵のパターンを管理するクラス
*
*/
class EnemyPatternManager
{
	
	//パターンの状態
	enum PatternState
	{
		//生成
		Pattern_Create,

		//実行
		Pattern_Run,

		//終了
		Pattern_End
	};
	
private:

	/**パターンクラス*/
	EnemyPattern* m_pEnemyPattern;

	/**現在のパターンID*/
	EnemyPatternID m_currentPatternID;

	/**次のパターンID*/
	EnemyPatternID m_nextPatternID;

	/**パターンの状態*/
	PatternState m_state;

	//パターン終了
	bool m_patternEnd;

public:

	//コンストラクタ
	EnemyPatternManager();
	//デストラクタ
	~EnemyPatternManager();

	//コントロール関数
	bool Control();

	//描画関数
	void Draw();


};

#endif