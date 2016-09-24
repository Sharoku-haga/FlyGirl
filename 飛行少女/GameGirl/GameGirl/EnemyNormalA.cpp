/**
*@file EnemyNormalA.cpp
*@brief �G�l�~�[A�N���X��cpp�t�@�C��
*@author�@�F��M�V
*2016/08/24����
*/
#include"Commonitems.h"
#include "EnemyNormalA.h"

Texture EnemyNormalA::m_enemyATex ;


/**�R���X�g���N�^*/
EnemyNormalA::EnemyNormalA(D3DXVECTOR2 enemy)
{
	m_enemyPos.x = enemy.x;
	m_enemyPos.y = enemy.y;

	m_enemyMoveType = NormalMove;

	m_animePatternCount = 0;

	if (EnemyNormalA::m_enemyATex.GetStateTex() == NULL)
	{
		EnemyNormalA::m_enemyATex.GetDevice();
		EnemyNormalA::m_enemyATex.LoadTexEx("Picture\\GameScene\\EnemyPatternManager\\th_kedama2.png", 255, 0, 0, 0, false);
	}
	
}


/**�f�X�g���N�^*/
EnemyNormalA::~EnemyNormalA()
{
	
}

/**�R���g���[���֐�*/
bool EnemyNormalA::Control()
{
	//�����̍��W�œ�������ύX������
	if (m_initFlag)
	{
		if (m_enemyPos.x <= GAMESTAGE_POS_X)
		{
			m_enemyMoveType = RightMove;
		}
		else if (m_enemyPos.x >= (GAMESTAGE_POS_X + GAMESTAGE_W))
		{
			m_enemyMoveType = LeftMove;
		}
		else
		{
			m_enemyMoveType = NormalMove;
		}

		m_initFlag = false;
	}

	//�Փ˔���
	if (!m_hitFlag)
	{
		//�v���C���[�Ƃ̏Փ˔�����s��
		m_collision->CollisionCheckPlayer(&m_enemyPos);

		//�v���C���[�e�Ƃ̏Փ˔�����s��
		if (m_collision->CollisionCheckPlayerBullet(&m_enemyPos))
		{
			m_hitFlag = true;
			m_effect.SetEffectPos(m_enemyPos);
		
		}
	}


	if (!m_hitFlag)
	{
		MoveEnemy();
	}
	else
	{
		//�G�t�F�N�g�̃A�j���[�V�������I���ΏI���t���O�����Ă�
		if (m_effect.GetAnimeState())
		{
			m_endFlag = true;
		}
	}

	return m_endFlag;
}

/**�`��֐�*/
void EnemyNormalA::Draw()
{
	if (!m_hitFlag)
	{
		//�GA�̒��_���
		CUSTOMVERTEX enemynomalA[] =
		{
			{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,         0.0f,         0.0f },
			{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, ENEMY_TEX_TU,         0.0f },
			{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, ENEMY_TEX_TU, ENEMY_TEX_TV },
			{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,         0.0f, ENEMY_TEX_TV },
		};

		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			m_vertex[i] = enemynomalA[i];

			m_vertex[i].x += m_enemyPos.x;
			m_vertex[i].y += m_enemyPos.y;
		}

		//�A�j���[�V�����p�^�[���ɂ��킹��tv�l��ω�
		for (int i = 0; i < VERTEX_NUMBER; i++)
		{
			m_vertex[i].tv += (ENEMY_TEX_TV * m_animePatternCount);
		}

		if (m_animePatternCount < ENEMY_A_PATTERN)
		{
			m_animePatternCount++;
		}
		else
		{
			m_animePatternCount = 0;
		}

		EnemyNormalA::m_enemyATex.RenderTex(m_vertex);
	}
	else
	{
		m_effect.Draw();
	}
}


/**�G�̓������Ǘ�����֐�*/
void EnemyNormalA::MoveEnemy()
{
	//ID�ɂ���ē����p�^�[����ς���
	switch (m_enemyMoveType)
	{
	case LeftMove:
		m_enemyPos.x -= ENEMY_A_MOVE_SPEED;
		

		if (m_enemyPos.x <= GAMESTAGE_POS_X)
		{
			m_hitFlag = true;
			m_endFlag = true;
		}

		break;

	case RightMove:
		m_enemyPos.x += ENEMY_A_MOVE_SPEED;
		

		if (m_enemyPos.x >= (GAMESTAGE_POS_X + GAMESTAGE_W))
		{
			m_hitFlag = true;
			m_endFlag = true;
		}
		break;

	case NormalMove:

		m_enemyPos.y += ENEMY_A_MOVE_SPEED;
		if (m_enemyPos.y >= (GAMESTAGE_H + GAMESTAGE_POS_Y))
		{
			m_hitFlag = true;
			m_endFlag = true;
		}

		break;

	};
}