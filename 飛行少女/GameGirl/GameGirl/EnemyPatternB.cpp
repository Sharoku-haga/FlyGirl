#include "EnemyPatternB.h"


//コンストラクタ
EnemyPatternB::EnemyPatternB()
{
	m_enemyStartPos.x = 850.f;
	m_enemyStartPos.y = 300.f;

	m_enemyNomalA_Count = 0;
}


//デストラクタ
EnemyPatternB::~EnemyPatternB()
{
	m_enemyNomalA.clear();
}


//コントロール関数
EnemyPatternID EnemyPatternB::Control()
{
	//時間をカウント
	static int enemyPatternTime = 0;

	//敵を作り出す
	if ((enemyPatternTime % ENEMY_INTERVAL) == 0)
	{
		if (m_enemyNomalA_Count < ENEMYNORMAL_A)
		{
			m_enemyNomalA.push_back(EnemyNormalA(m_enemyStartPos));
			m_enemyNomalA_Count++;
		}
	}


	//敵の動きを確認
	for (auto itr = m_enemyNomalA.begin(); itr != m_enemyNomalA.end();)
	{
		if (itr->Control())
		{
			itr = m_enemyNomalA.erase(itr);
		} 
		else
		{
			itr++;
		}

	}

	if (m_enemyNomalA.size() <= 0 && m_enemyNomalA_Count == ENEMYNORMAL_A)
	{
		return Enemy_patternA;
	}

	enemyPatternTime++;
	

	return Enemy_patternB;
}

//描画関数
void EnemyPatternB::Draw()
{
	//敵を描画
	for (auto itr = m_enemyNomalA.begin(); itr != m_enemyNomalA.end();)
	{
		itr->Draw();
		itr++;
	}
}