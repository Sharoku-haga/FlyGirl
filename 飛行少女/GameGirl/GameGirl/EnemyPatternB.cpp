#include "EnemyPatternB.h"


//�R���X�g���N�^
EnemyPatternB::EnemyPatternB()
{
	m_enemyStartPos.x = 850.f;
	m_enemyStartPos.y = 300.f;

	m_enemyNomalA_Count = 0;
}


//�f�X�g���N�^
EnemyPatternB::~EnemyPatternB()
{
	m_enemyNomalA.clear();
}


//�R���g���[���֐�
EnemyPatternID EnemyPatternB::Control()
{
	//���Ԃ��J�E���g
	static int enemyPatternTime = 0;

	//�G�����o��
	if ((enemyPatternTime % ENEMY_INTERVAL) == 0)
	{
		if (m_enemyNomalA_Count < ENEMYNORMAL_A)
		{
			m_enemyNomalA.push_back(EnemyNormalA(m_enemyStartPos));
			m_enemyNomalA_Count++;
		}
	}


	//�G�̓������m�F
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

//�`��֐�
void EnemyPatternB::Draw()
{
	//�G��`��
	for (auto itr = m_enemyNomalA.begin(); itr != m_enemyNomalA.end();)
	{
		itr->Draw();
		itr++;
	}
}