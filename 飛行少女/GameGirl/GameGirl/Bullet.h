/**
*@file Bullet.h
*@brief �e�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/22����
*/
#ifndef BULLET_H
#define BULLET_H

#include"LibClass.h"
#include"CommonItems.h"

/**�e�̃e�N�X�`���[�T�C�Y*/
#define B_TEXSIZE 64.f

/**
*�e�̊�{�N���X
*
*/
class Bullet
{
protected:

	/*�e�̈ʒu*/
	D3DXVECTOR2 m_bulletPos;

	/*�`��t���O*/
	bool m_hitFlag;

	/**�o�[�e�b�N�X���*/
	CUSTOMVERTEX m_vertex[VERTEX_NUMBER];

public:
	//�R���X�g���N�^
	Bullet(){};
	//�f�X�g���N�^
	virtual ~Bullet(){};

	/**�����艺�̉��z�֐��͒e�̂ӂ�܂��𗬓��I�ɂ�����ꍇ��z�肵�Ď������Ă���*/

	/**�R���g���[���֐�*/
	virtual bool Control() = 0;

	/**�`��ʒu���擾����֐�*/
	virtual CUSTOMVERTEX* GetDrawPos() = 0;


};


#endif