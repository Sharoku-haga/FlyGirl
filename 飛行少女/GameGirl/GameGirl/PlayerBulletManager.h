/**
*@file PlayerBulletManager.h
*@brief	�v���C���[�e���Ǘ�����N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/22����
*/
#ifndef PLAYER_BULLET_MANAGER_H
#define PLAYER_BULLET_MANAGER_H

#include<list>
#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"
#include "Collision.h"

using namespace std;

/**�e�̊Ԋu*/
#define BULLET_INTEVAL 5

/**
*�v���C���[�e�̐��A�y�ѕ`����Ǘ�����N���X
*/
class PlayerBulletManager
{
private:

	/**�v���C���[�̃e�N�`���[���i�[����ϐ�*/
	Texture m_bulletTex_P;

	/**���X�g�\���̃o���b�g*/
	list<PlayerBullet> m_bullet;

	/**�e�̘A�˂ɂ�����Ԋu*/
	int m_bulletInterval;

	/**�Փ˔���*/
	Collision* m_collision;

public:

	/**�R���X�g�^�N�^*/
	PlayerBulletManager();

	/**�f�X�g���N�^*/
	~PlayerBulletManager();

	/**�R���g���[���֐�*/
	void Control();

	/**�`��֐�*/
	void Draw();

	/**
	*�e�����o���֐�<br>
	*param[in] player �v���C���[�̌��݂̍��W
	*
	*/
	void CreateBullet(D3DXVECTOR2 player);




};


#endif