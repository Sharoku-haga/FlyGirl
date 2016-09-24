/**
*@file Collision.h
*@brief �Փ˔���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef COLLISION_H
#define COLLISION_H

#include<list>
#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"

using namespace std;
 
//�v���C���[�̓����蔻�苗��
#define COLLSION_PLAYER_RENGE 25

//�v���C���[�e�̓����蔻�苗��
#define COLLSION_BULLET_RENGE 40


//�Փ˔���p�\����
struct CollisionState
{
	D3DXVECTOR2 pos;			//���W
	bool hitstate;			//�������Ă��邩�ǂ���
};


/**
*�Փ˔�����s���N���X
*
*/
class Collision
{
private:

	//�v���C���[�̃X�e�[�^�X���i�[����ϐ�
	CollisionState m_playerState;

	//�v���C���[�e�̃X�e�[�^�X���i�[����ϐ�
	list<CollisionState> m_playerBullet;


public:

	//�R���X�g���N�^
	Collision();

	//�f�X�g���N�^
	~Collision();

	//���̂��K��
	static Collision& GetInstance()
	{
		static Collision collision;

		return collision;
	}

	//�v���C���[�̃X�e�[�^�X���擾����
	void GetStatePlayer(const D3DXVECTOR2 player);

	//�v���C���[�̃q�b�g�t���O������
	void InitHitPlayer();

	//�v���C���[���������Ă��邩���v���C���[�I�u�W�F�N�g�ɂ��点��
	bool InformHitPlayer();

	//�v���C���[�Ƃ̏Փ˃`�F�b�N
	bool CollisionCheckPlayer(const D3DXVECTOR2* obj);



	//�v���C���[�e�̃X�e�[�^�X���擾����
	void GetStatePlayer(list<PlayerBullet> &bullet);

	//�v���C���[�e���������Ă��邩���v���C���[�e�ɒm�点��
	bool InformHitPlayerBullet(const D3DXVECTOR2* bullet);

	//�v���C���[�e�Ƃ̏Փ˃`�F�b�N
	bool CollisionCheckPlayerBullet(const D3DXVECTOR2* obj);


};

#endif