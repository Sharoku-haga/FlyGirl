/**
*@file PlayerBullet.h
*@brief	�v���C���[�e�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/22����
*/
#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include"LibClass.h"
#include"Bullet.h"

/**�v���C���[�e�̈ړ����x*/
#define PLAYER_BULLET_SPEED 15.f

/**�v���C���[�e��tu�l*/
#define PLAYER_BULLET_TU 0.2f
/**�v���C���[�e��tv�l*/
#define PLAYER_BULLET_TV 0.5f
/**�v���C���[�e�A�j���[�V�����p�^�[����*/
#define BULLET_ANIME_PATTERN 5
/**�v���C���[�e�A�j���[�V�����Ԋu*/
#define BULLET_ANIME_INTERVAL 1

/**
*�v���C���[�e�N���X
*
*/
class PlayerBullet :public Bullet
{
private:

	/**�v���C���[�e�̃A�j���p�^�[����*/
	int m_animePattern;

public:
	//�R���X�g���N�^
	PlayerBullet(D3DXVECTOR2 player);
	//�f�X�g���N�^
	~PlayerBullet();


	//�e�̍��W���擾����֐�
	D3DXVECTOR2 GetPosBullet(){ return m_bulletPos; }

	//�R���g���[���֐�
	virtual bool Control();

	/**�`��ʒu���擾����֐�*/
	virtual CUSTOMVERTEX* GetDrawPos();

};




#endif