/**
*@file Collision.cpp
*@brief �Փ˔���N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/

#include "Collision.h"

//�R���X�g���N�^
Collision::Collision()
{
	m_playerState.hitstate = false;
}

//�f�X�g���N�^
Collision::~Collision()
{
	m_playerBullet.clear();
}

//�v���C���[�̃X�e�[�^�X���擾����
void Collision::GetStatePlayer(const D3DXVECTOR2 player)
{
	
		m_playerState.pos.x = player.x;
		m_playerState.pos.y = player.y;
	
}

//�v���C���[�̃q�b�g�t���O������
void Collision::InitHitPlayer()
{
	m_playerState.hitstate = false;
}

//�v���C���[���������Ă��邩���v���C���[�I�u�W�F�N�g�ɂ��点��
bool Collision::InformHitPlayer()
{
	return m_playerState.hitstate;
}


//�v���C���[�Ƃ̏Փ˃`�F�b�N
bool Collision::CollisionCheckPlayer(const D3DXVECTOR2* obj)
{
	//���łɏՓ˂��Ă����炩����
	if (m_playerState.hitstate)
	{
		return false;
	}
	else
	{
		//�������Ă�����true��������
		if ((abs(obj->y - m_playerState.pos.y)) <= COLLSION_PLAYER_RENGE && (abs(obj->x - m_playerState.pos.x)) <= COLLSION_PLAYER_RENGE)
		{
			m_playerState.hitstate = true;

			return true;
		}
	}

	return false;
}


//�v���C���[�e�̃X�e�[�^�X���擾����
void Collision::GetStatePlayer(list<PlayerBullet> &bullet)
{
	//�擾�O�ɑS�ď���������
	if (m_playerBullet.size() > 0)
	{
		m_playerBullet.clear();

	}

	//�C�e���[�^���񂵂ăf�[�^���擾����
	for (auto itr = bullet.begin(); itr != bullet.end();)
	{
		m_playerBullet.push_back(CollisionState{itr->GetPosBullet(),false});

		itr++;
	}

	return;
}

//�v���C���[�e���������Ă��邩���v���C���[�e�ɒm�点��
bool Collision::InformHitPlayerBullet(const D3DXVECTOR2* bullet)
{
	for (auto itr = m_playerBullet.begin(); itr != m_playerBullet.end();)
	{
		//���W�Œe�����ʂ��適�����͂̂��ɏC��������
		if (itr->pos.x == bullet->x && itr->pos.y == bullet->y)
		{
			//�������Ă���ΏՓ˔���p�f�[�^��������true��Ԃ�
			if (itr->hitstate)
			{
				m_playerBullet.erase(itr);
				return true;
			}
			break;
		}
		else
		{
			itr++;
		}

	}


	return false;
}

//�v���C���[�e�Ƃ̏Փ˃`�F�b�N
bool Collision::CollisionCheckPlayerBullet(const D3DXVECTOR2* obj)
{
	for (auto itr = m_playerBullet.begin(); itr != m_playerBullet.end();)
	{
		if (!itr->hitstate)
		{
			//�������Ă�����true��������
			if ((abs(obj->y - itr->pos.y)) <= COLLSION_BULLET_RENGE && (abs(obj->x - itr->pos.x)) <= COLLSION_BULLET_RENGE)
			{
				itr->hitstate = true;

				return true;
			}
		}
	
		itr++;
	}

	return false;
}