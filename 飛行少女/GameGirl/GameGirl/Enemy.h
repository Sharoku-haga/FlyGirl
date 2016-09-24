/**
*@file Enemy.h
*@brief �G�l�~�[�N���X�̃w�b�_�[�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#ifndef ENEMY_H
#define ENEMY_H

#include"LibClass.h"
#include"CommonItems.h"
#include "Collision.h"

/**�G�̓�����������ID*/
enum EnmeyMoveType
{
	RightMove,		//�E�ɓ���
	LeftMove,		//���ɓ���
	NormalMove		//���ɓ���
};

/**�G�摜��tu�l*/
#define ENEMY_TEX_TU 0.083f
/**�G�摜��tu�l*/
#define ENEMY_TEX_TV 0.25f


/**
*�G�̃N���X
*
*/
class Enemy
{

protected:

	//�G�̈ʒu���W
	D3DXVECTOR2 m_enemyPos;

	//�G�̏����ʒu�������ϐ�
	EnmeyMoveType m_enemyMoveType;

	/**�Փ˔���*/
	Collision* m_collision;

	/**�������t���O*/
	bool m_initFlag;

	/**������t���O*/
	bool m_hitFlag;

	/**t�G�̏I���t���O*/
	bool m_endFlag;

	/**�o�[�e�b�N�X���*/
	CUSTOMVERTEX m_vertex[VERTEX_NUMBER];


public:

	Enemy()
	{
		m_collision = &Collision::GetInstance();
		m_endFlag = false;

		m_hitFlag = false;
		m_initFlag = true;
	};
	virtual~Enemy(){};

	/**���W���擾����֐�*/
	D3DXVECTOR2 GetPos(){ return m_enemyPos; }

	/**�`��ʒu���擾����֐�*/
	CUSTOMVERTEX* GetDrawPos(){ return m_vertex; };

	/**�����艺�̉��z�֐��͒e�̂ӂ�܂��𗬓��I�ɂ�����ꍇ��z�肵�Ď������Ă���*/

	/**�R���g���[���֐�*/
	virtual bool Control() = 0;

	/**�`��֐�*/
	virtual void Draw() = 0;

};



#endif