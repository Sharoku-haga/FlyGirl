#include "EnemyPatternA.h"


//コンストラクタ
EnemyPatternA::EnemyPatternA()
{
	//2016/09/04適当な値をいれている
	/**敵の初期位置*/
	m_enemyStartPos.x = 50.f;
	m_enemyStartPos.y = 200.f;

	m_enemyNomalA_Count = 0;

}

//デストラクタ
EnemyPatternA::~EnemyPatternA()
{
	m_enemyNomalA.clear();
}


//コントロール関数
EnemyPatternID EnemyPatternA::Control()
{
	//敵を生成する時間をカウント
	static int enemyPatternTime = 0;

	//敵を作り出す
	if ((enemyPatternTime % ENEMY_INTERVAL) == 0)
	{
		if (m_enemyNomalA_Count < ENEMYNORMAL_A_A)
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

	//敵がすべて生成されており、かつ敵がすべて消えていれば次のパターンへ
	if (m_enemyNomalA.size() <= 0 && m_enemyNomalA_Count == ENEMYNORMAL_A_A)
	{
		return Enemy_patternB;
	}
	enemyPatternTime++;

	return Enemy_patternA;
}


//描画関数
void EnemyPatternA::Draw()
{
	//敵を描画
	for (auto itr = m_enemyNomalA.begin(); itr != m_enemyNomalA.end();)
	{
		itr->Draw();

		itr++;
	}
}