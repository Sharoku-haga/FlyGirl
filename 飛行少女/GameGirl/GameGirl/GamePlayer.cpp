/**
*@file GamePlayer.cpp
*@brief �Q�[���v���C���[�N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/20����
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"GamePlayer.h"
#include"PlayerBulletManager.h"

//�R���X�g���N�^
GamePlayer::GamePlayer()
{
	m_playerTex.LoadTexEx("Picture\\GameScene\\GamePlayer\\Player.png", 255, 0, 0, 0, false);
	m_slowModeTex.LoadTexEx("Picture\\GameScene\\GamePlayer\\center16.png", 255, 0, 0, 0, false);
	m_playerPos.x = P_POSX_INITVAL;
	m_playerPos.y = P_POSY_INITVAL;
	m_moveSpeed = P_MOVE_SPEED_DEFAULT;
	m_collision = &Collision::GetInstance();
	m_playerLife = LIFE_INITVAL;
	m_animePattern = 0;
	m_animeReverse = false;
	m_playerState = NORMAL;
}

//�f�X�g���N�^
GamePlayer::~GamePlayer()
{
}

// �R���g���[���֐�
bool GamePlayer::Control()
{
	// �Փ˂��Ă��邩���m�F
	if (m_collision->InformHitPlayer())
	{
		m_effectManager.SetHitEffectPos(&m_playerPos);
		m_playerState = HIT;
		
	}

	if (m_effectManager.GetStateInviEffect())
	{
		m_playerState = NORMAL;
	}

	// �������Ă��Ȃ���΃L�[���삪�s����
	if (m_playerState != HIT)
	{
		KeyControl();	
	}
	else
	{
		// �G�t�F�N�g���I�������
		if (m_effectManager.GetStateHitEffect())
		{
			// ������HP���ւ炵�Ă���
			// m_playerLife -= 1;

			if (m_playerLife >= 0)
			{
				//�G�t�F�N�g�I����
				m_playerState = INVINCIBLE;
				//�Փ˔���̃t���O�����Ƃɂ��ǂ�
				m_collision->InitHitPlayer();
				//�����ʒu�֖߂�
				m_playerPos.x = P_POSX_INITVAL;
				m_playerPos.y = P_POSY_INITVAL;
			}
			else
			{
				// ���C�t��0�Ȃ�true������
				return true;
			}
		}
		
	}

	//�������Ă��Ȃ���΍��W���킽��
	if (m_playerState != HIT)
	{
		// ���G��Ԓ��͏Փ˔���Ɂo0,0�p�̍��W���킽��
		if (m_playerState == INVINCIBLE)
		{
			D3DXVECTOR2 invinciblePos = {0,0};
			m_collision->GetStatePlayer(invinciblePos);
		}
		else
		{
			m_collision->GetStatePlayer(m_playerPos);
		}
	}
	m_playerBulletManager.Control();

	return false;
}


// �`��֐�
void GamePlayer::Draw()
{

	//�������ĂȂ���Βʏ�`��
	if (m_playerState != HIT)
	{
		//�e�̕`��
		m_playerBulletManager.Draw();

		DrawNormal();

		if (m_moveSpeed == P_MOVE_SPEED_SHIFT)
		{
			// �ᑬ���[�h�Ȃ�_��`��
			DrawSlowMode();
		}

		if (m_playerState == INVINCIBLE)
		{
			m_effectManager.DrawInviEffect(&m_playerPos);
		}

	}
	else
	{
		// �q�b�g�G�t�F�N�g��`��
		m_effectManager.DrawHitEffect();
	}

}


//�R���g���[���L�[����
void GamePlayer::KeyControl()
{
	
	m_gameKey.UpdateKey();

	// �L�[��Ԃ��m�F
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_UP], UP);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_DOWN], DOWN);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_RIGHT], RIGHT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LEFT], LEFT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LSHIFT], SHIFT);

	// shift�������ƒᑬ���[�h�ɐ؂�ւ��
	if (m_gameKey.m_Key[SHIFT] == ON)
	{
		m_moveSpeed = P_MOVE_SPEED_SHIFT;
	}
	else
	{
		m_moveSpeed = P_MOVE_SPEED_DEFAULT;
	}

	if (m_gameKey.m_Key[UP] == ON)
	{
		if (m_playerPos.y >= (GAMESTAGE_POS_Y + PLAYER_RANGE))
		{
			m_playerPos.y -= m_moveSpeed;
		}

	}
	if (m_gameKey.m_Key[DOWN] == ON)
	{
		if (m_playerPos.y <= (GAMESTAGE_H + GAMESTAGE_POS_Y - PLAYER_RANGE))
		{
			m_playerPos.y += m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[RIGHT] == ON)
	{
		if (m_playerPos.x <= (GAMESTAGE_W + GAMESTAGE_POS_X - PLAYER_RANGE))
		{
			m_playerPos.x += m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[LEFT] == ON)
	{
		if (m_playerPos.x >= GAMESTAGE_POS_X + PLAYER_RANGE)
		{
			m_playerPos.x -= m_moveSpeed;
		}
	}
	if (m_gameKey.m_Key[Z] == PUSH || m_gameKey.m_Key[Z] == ON)
	{
		// �e����
		m_playerBulletManager.CreateBullet(m_playerPos);
	
	}

}

// �v���C���[��`�悷��֐�
void GamePlayer::DrawNormal()
{
	// �v���C���[�̒��_���
	CUSTOMVERTEX player[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,          0.0f,          0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_TEX_TU,          0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, PLAYER_TEX_TU, PLAYER_TEX_TV },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,          0.0f, PLAYER_TEX_TV },
	};

	//�`��p�̕ϐ�
	CUSTOMVERTEX drawPlayer[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawPlayer[i] = player[i];

		drawPlayer[i].x += m_playerPos.x;
		drawPlayer[i].y += m_playerPos.y;

	}

	if (m_animePattern != 0)
	{
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			drawPlayer[i].tu += (PLAYER_TEX_TU * m_animePattern);
		}

	}

	//�A�j���[�V�������Ԃ��J�E���g
	static int playerAnimeTime = 0;
	playerAnimeTime++;

	if ((playerAnimeTime % PLAYER_ANIME_INTERVAL) == 0)
	{
		if (!m_animeReverse)
		{
			m_animePattern++;

			if (m_animePattern == PLAYER_ANIME_PATTERN)
			{
				m_animeReverse = true;
			}
		}
		else
		{
			m_animePattern--;
			if (m_animePattern == 0)
			{
				m_animeReverse = false;
				playerAnimeTime = 0;
			}
		}

	}

	if (m_playerState == INVINCIBLE)
	{
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			drawPlayer[i].color = 0x99FFFFFF;
		}
	}

	m_playerTex.RenderTex(drawPlayer);

}

// �ᑬ���[�h�ɂ�����摜��`�悷��֐�
void GamePlayer::DrawSlowMode()
{
	//�ᑬ���[�h�ɂ�����_�̒��_���
	CUSTOMVERTEX slowPoint[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//�`��p�̕ϐ�
	CUSTOMVERTEX drawPoint[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawPoint[i] = slowPoint[i];

		drawPoint[i].x += m_playerPos.x;
		drawPoint[i].y += m_playerPos.y;
	}

	m_slowModeTex.RenderTex(drawPoint);
}