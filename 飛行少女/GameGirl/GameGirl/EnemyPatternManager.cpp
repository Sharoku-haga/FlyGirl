/**
*@file EnemyPatternManager.cpp
*@brief エネミーパターンマネージャークラスのcppファイル
*@author　芳我貴之
*2016/08/24制作
*/
#include"CommonItems.h"
#include "EnemyPatternManager.h"
#include "EnemyPattern.h"
#include "EnemyPatternFactory.h"


//コンストラクタ
EnemyPatternManager::EnemyPatternManager()
{

	m_pEnemyPattern = nullptr;

	m_currentPatternID = Enemy_patternA;

	m_nextPatternID = Enemy_patternA;

	m_state = Pattern_Create;

	m_patternEnd = false;
} 

//デストラクタ
EnemyPatternManager::~EnemyPatternManager()
{
	
	if (m_pEnemyPattern != nullptr)
	{
		delete m_pEnemyPattern;

		m_pEnemyPattern = nullptr;
	}
	
}


//コントロール関数(パターン終了したらtrueをかえす)
bool EnemyPatternManager::Control()
{
	if (m_pEnemyPattern == nullptr)
	{
		m_currentPatternID = m_nextPatternID;
		if (m_currentPatternID == EnemyEnd)
		{
			m_patternEnd = true;

			return m_patternEnd;
		}
	}
	
	switch (m_state)
	{
	case Pattern_Create:

		//パターンIDをもとにパターンを作成
		m_pEnemyPattern = EnemyPatternFactory::Instance().CreateEnemyPattern(m_currentPatternID);

		//次の状態へ移行
		m_state = Pattern_Run;

		break;

	case Pattern_Run:

		//パターンIDが違えば次のパターンの生成にうつる
		if ((m_nextPatternID = m_pEnemyPattern->Control()) != m_currentPatternID)
		{
			m_state = Pattern_End;
		}

		break;

	case Pattern_End:

		delete m_pEnemyPattern;
		m_pEnemyPattern = nullptr;

		//次のシーンを作成できる状態にする
		m_state = Pattern_Create;

		break;

	};

	return m_patternEnd;
}

//描画関数
void EnemyPatternManager::Draw()
{
	
	//パターン
	if (m_state == Pattern_Run)
	{
		m_pEnemyPattern->Draw();
	}
	else
	{
		return;
	}
	
}
