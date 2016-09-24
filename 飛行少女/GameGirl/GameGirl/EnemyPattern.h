/**
*@file EnemyPattern.h
*@brief �G�l�~�[�p�^�[���N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#ifndef ENEMY_PATTERN_H
#define ENEMY_PATTERN_H

#include"CommonItems.h"

/**
*�G�̃p�^�[���̊��N���X
*
*/
class EnemyPattern
{
private:

public:

	//�R���X�g���N�^
	EnemyPattern(){};

	//�f�X�g���N�^
	virtual ~EnemyPattern(){};

	//�R���g���[���֐�
	virtual EnemyPatternID Control() = 0;

	//�`��֐�
	virtual void Draw() = 0;
};

#endif