/**
*@file EnemyPatternFactory.h
*@brief �G�l�~�[�p�^�[���t�@�N�g���[�N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/23����
*/
#ifndef ENEMY_PATTERN_FACTORY_H
#define ENEMY_PATTERN_FACTORY_H

#include"CommonItems.h"
#include "EnemyPattern.h"
#include "EnemyPatternA.h"

/**
*�G�p�^�[���̐������s���N���X
*/
class EnemyPatternFactory
{
public:
	//�R���X�g���N�^
	EnemyPatternFactory(){};
	//�f�X�g���N�^
	~EnemyPatternFactory(){};

	//���̉��i�ʂ�static�ł͂Ȃ��A���ʂ�EnemyPatternManager�ɂ�������̂��P�̈āj
	static EnemyPatternFactory& Instance()
	{
		static EnemyPatternFactory enemyPatternFactory;

		return enemyPatternFactory;
	}

	//�G�̃p�^�[�����쐬
	EnemyPattern* CreateEnemyPattern(EnemyPatternID enemyPattern);

};


#endif