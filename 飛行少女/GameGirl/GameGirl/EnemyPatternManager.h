/**
*@file EnemyPatternManager.h
*@brief �G�l�~�[�p�^�[���}�l�[�W���[�N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/23����
*/
#ifndef ENEMY_PATTERN_MANAGER_H
#define ENEMY_PATTERN_MANAGER_H

#include"CommonItems.h"
#include "EnemyPatternFactory.h"
#include "EnemyPattern.h"
/**
*�G�̃p�^�[�����Ǘ�����N���X
*
*/
class EnemyPatternManager
{
	
	//�p�^�[���̏��
	enum PatternState
	{
		//����
		Pattern_Create,

		//���s
		Pattern_Run,

		//�I��
		Pattern_End
	};
	
private:

	/**�p�^�[���N���X*/
	EnemyPattern* m_pEnemyPattern;

	/**���݂̃p�^�[��ID*/
	EnemyPatternID m_currentPatternID;

	/**���̃p�^�[��ID*/
	EnemyPatternID m_nextPatternID;

	/**�p�^�[���̏��*/
	PatternState m_state;

	//�p�^�[���I��
	bool m_patternEnd;

public:

	//�R���X�g���N�^
	EnemyPatternManager();
	//�f�X�g���N�^
	~EnemyPatternManager();

	//�R���g���[���֐�
	bool Control();

	//�`��֐�
	void Draw();


};

#endif