/**
*@file EnemyPatternA.h
*@brief �G�l�~�[�p�^�[��A�N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#ifndef ENEMY_PATTERN_A_H
#define ENEMY_PATTERN_A_H

#include"LibClass.h"
#include "EnemyPattern.h"
#include "EnemyNormalA.h"
#include <list>      
using namespace std;



/**
*�G�l�~�[�p�^�[��A���Ǘ�����
*/
class EnemyPatternA :public EnemyPattern
{
private:
//�p�^�[��A�ɂ�����GA�̐�
#define ENEMYNORMAL_A_A 2

//�G�̏o���Ԋu
#define ENEMY_INTERVAL 20

	//�GA�̏o���ʒu
	D3DXVECTOR2 m_enemyStartPos;
	//�GA
	list<EnemyNormalA> m_enemyNomalA;
	//�GA�̃J�E���g��
	int m_enemyNomalA_Count;

public:

	//�R���X�g���N�^
	EnemyPatternA();
	//�f�X�g���N�^
	~EnemyPatternA();

	//�R���g���[���֐�
	virtual EnemyPatternID Control();

	//�`��֐�
	virtual void Draw();
};


#endif
