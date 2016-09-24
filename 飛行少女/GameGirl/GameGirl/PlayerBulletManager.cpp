/**
*@file PlayerBulletManager.cpp
*@brief	�v���C���[�e���Ǘ�����N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/22����
*/

#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBullet.h"
#include"PlayerBulletManager.h"


// �R���X�g���N�^
PlayerBulletManager::PlayerBulletManager()
{
	// �e�N�X�`���[��ǂ݂���
	m_bulletTex_P.LoadTexEx("Picture\\GameScene\\GamePlayer\\PlayerBulletManager\\playerBullet01.png", 255, 0, 0, 0, false);
	m_collision = &Collision::GetInstance();
	m_bulletInterval = 0;

}

// �f�X�g���N�^
PlayerBulletManager::~PlayerBulletManager()
{
	// �S�v�f���폜����
	m_bullet.clear();
}


// �R���g���[���֐�
void PlayerBulletManager::Control()
{

	// �Փ˔���
	if (m_bullet.size() > 0)
	{
		for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
		{
			if (m_collision->InformHitPlayerBullet(&(itr->GetPosBullet())))
			{
				itr = m_bullet.erase(itr);
			}
			else
			{
				itr++;
			}
		}
	}

	// �v���C���[���q�b�g���Ă����炷�ׂĒe������
	if (m_collision->InformHitPlayer())
	{
		m_bullet.clear();

		return;
	}
	

	// �e�̃R���g���[���A�y�я�Ԋm�F
	for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
	{
		if (itr->Control())
		{
			itr = m_bullet.erase(itr);
		}
		else
		{
			itr++;
		}
		
	}

	if (m_bullet.size() > 0)
	{
		// ���W���Փ˔���ɓo�^����
		m_collision->GetStatePlayer(m_bullet);
	}

	m_bulletInterval++;
	
	if (m_bullet.size() == 0)
	{
		m_bulletInterval = 0;
	}

}


// �`��֐�
void PlayerBulletManager::Draw()
{
	// �e��`��
	for (auto itr = m_bullet.begin(); itr != m_bullet.end();)
	{
		m_bulletTex_P.RenderTex(itr->GetDrawPos());

		itr++;
	}

}

// �e�����o���֐�
void PlayerBulletManager::CreateBullet(D3DXVECTOR2 player)
{
	if (m_bulletInterval % BULLET_INTEVAL == 0)
	{
		m_bullet.push_back(PlayerBullet(player));
		m_bulletInterval = 0;
	}
	

}
