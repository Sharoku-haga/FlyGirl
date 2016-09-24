#include "EnemyPatternA.h"


//�R���X�g���N�^
EnemyPatternA::EnemyPatternA()
{
	//2016/09/04�K���Ȓl������Ă���
	/**�G�̏����ʒu*/
	m_enemyStartPos.x = 50.f;
	m_enemyStartPos.y = 200.f;

	m_enemyNomalA_Count = 0;

}

//�f�X�g���N�^
EnemyPatternA::~EnemyPatternA()
{
	m_enemyNomalA.clear();
}


//�R���g���[���֐�
EnemyPatternID EnemyPatternA::Control()
{
	//�G�𐶐����鎞�Ԃ��J�E���g
	static int enemyPatternTime = 0;

	//�G�����o��
	if ((enemyPatternTime % ENEMY_INTERVAL) == 0)
	{
		if (m_enemyNomalA_Count < ENEMYNORMAL_A_A)
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

	//�G�����ׂĐ�������Ă���A���G�����ׂď����Ă���Ύ��̃p�^�[����
	if (m_enemyNomalA.size() <= 0 && m_enemyNomalA_Count == ENEMYNORMAL_A_A)
	{
		return Enemy_patternB;
	}
	enemyPatternTime++;

	return Enemy_patternA;
}


//�`��֐�
void EnemyPatternA::Draw()
{
	//�G��`��
	for (auto itr = m_enemyNomalA.begin(); itr != m_enemyNomalA.end();)
	{
		itr->Draw();

		itr++;
	}
}