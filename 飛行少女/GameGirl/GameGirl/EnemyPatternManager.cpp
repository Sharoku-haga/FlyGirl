/**
*@file EnemyPatternManager.cpp
*@brief �G�l�~�[�p�^�[���}�l�[�W���[�N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#include"CommonItems.h"
#include "EnemyPatternManager.h"
#include "EnemyPattern.h"
#include "EnemyPatternFactory.h"


//�R���X�g���N�^
EnemyPatternManager::EnemyPatternManager()
{

	m_pEnemyPattern = nullptr;

	m_currentPatternID = Enemy_patternA;

	m_nextPatternID = Enemy_patternA;

	m_state = Pattern_Create;

	m_patternEnd = false;
} 

//�f�X�g���N�^
EnemyPatternManager::~EnemyPatternManager()
{
	
	if (m_pEnemyPattern != nullptr)
	{
		delete m_pEnemyPattern;

		m_pEnemyPattern = nullptr;
	}
	
}


//�R���g���[���֐�(�p�^�[���I��������true��������)
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

		//�p�^�[��ID�����ƂɃp�^�[�����쐬
		m_pEnemyPattern = EnemyPatternFactory::Instance().CreateEnemyPattern(m_currentPatternID);

		//���̏�Ԃֈڍs
		m_state = Pattern_Run;

		break;

	case Pattern_Run:

		//�p�^�[��ID���Ⴆ�Ύ��̃p�^�[���̐����ɂ���
		if ((m_nextPatternID = m_pEnemyPattern->Control()) != m_currentPatternID)
		{
			m_state = Pattern_End;
		}

		break;

	case Pattern_End:

		delete m_pEnemyPattern;
		m_pEnemyPattern = nullptr;

		//���̃V�[�����쐬�ł����Ԃɂ���
		m_state = Pattern_Create;

		break;

	};

	return m_patternEnd;
}

//�`��֐�
void EnemyPatternManager::Draw()
{
	
	//�p�^�[��
	if (m_state == Pattern_Run)
	{
		m_pEnemyPattern->Draw();
	}
	else
	{
		return;
	}
	
}
