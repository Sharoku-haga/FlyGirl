/**
*@file EnemyNormalA.h
*@brief �G�l�~�[A�N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#ifndef ENEMY_NORMAL_A_H
#define ENEMY_NORMAL_A_H

#include "Enemy.h"
#include "Effect.h"
#include "WaveEffect.h"

/**�GA�̓����X�s�[�h*/
#define ENEMY_A_MOVE_SPEED 3.f

//�G�̃A�j���[�V�����R�}��
#define ENEMY_A_PATTERN 4

/**
*�ʏ�G��A�^�C�v�̃N���X
*
*/
class EnemyNormalA :public Enemy
{
private:

	/**�G�t�F�N�g�N���X*/
	WaveEffect m_effect;
	

	//�G�̃A�j���p�^�[���J�E���g��
	int m_animePatternCount;

public:
	
	/**�G�N���XA�̃e�N�X�`���[���i�[����ϐ�*/
	static Texture m_enemyATex;

	/**�R���X�g���N�^*/
	EnemyNormalA(D3DXVECTOR2 enemy);
	/**�f�X�g���N�^*/
	~EnemyNormalA();

	/**�R���g���[���֐�*/
	bool Control();

	/**�`��֐�*/
	void Draw();

	/**�G�̓������Ǘ�����֐�*/
	void MoveEnemy();


};

#endif