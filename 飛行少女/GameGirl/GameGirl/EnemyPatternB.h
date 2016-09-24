/**
*@file EnemyNormalB.cpp
*@brief �G�l�~�[B�N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#ifndef ENEMY_PATTERN_B_H
#define ENEMY_PATTERN_B_H

#include"LibClass.h"
#include "EnemyPattern.h"
#include "EnemyNormalA.h"
#include <list>      
using namespace std;


class EnemyPatternB :public EnemyPattern
{
private:
	//�G�̐�
#define ENEMYNORMAL_A 10

	//�G�̏o���Ԋu
#define ENEMY_INTERVAL 20

	//�GA�̏o���ʒu
	D3DXVECTOR2 m_enemyStartPos;
	//�GA
	list<EnemyNormalA> m_enemyNomalA;
	//�GA�̃J�E���g��
	int m_enemyNomalA_Count;

public:

	EnemyPatternB();

	~EnemyPatternB();

	//�R���g���[���֐�
	virtual EnemyPatternID Control();

	//�`��֐�
	virtual void Draw();
};

#endif