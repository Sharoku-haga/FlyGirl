/**
*@file RotheCircle.h
*@brief ��]����~�̃G�t�F�N�g�N���X��cpp
*
*/
#include "RotheCircle.h"

Texture RotheCircle::m_rotheCircleTex;

// �R���X�g���N�^
RotheCircle::RotheCircle()
{
	//  �e�N�X�`���[�ǂݍ���
	if (RotheCircle::m_rotheCircleTex.GetStateTex() == NULL)
	{
		RotheCircle::m_rotheCircleTex.GetDevice();
		RotheCircle::m_rotheCircleTex.LoadTexEx("Picture\\GameScene\\Effect\\rotation01.png", 255, 0, 0, 0, false);
	}
}

// �f�X�g���N�^
RotheCircle::~RotheCircle()
{
}

// �`��֐�
void RotheCircle::Draw()
{
	// ��]�G�t�F�N�g�̒��_���
	CUSTOMVERTEX rotheCircleEffect[]
	{
		{ -ROTHE_TEXSIZE / 2.0f, -ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 0.0f },
		{  ROTHE_TEXSIZE / 2.0f, -ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.2f, 0.0f },
		{  ROTHE_TEXSIZE / 2.0f,  ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.2f, 1.0f },
		{ -ROTHE_TEXSIZE / 2.0f,  ROTHE_TEXSIZE / 2.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 1.0f },
	};

	// �`��p�̋�̊�
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawEffect[i] = rotheCircleEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//�A�j���[�V�����̕ω�
	if (m_animeCount > 0)
	{
		// 4�̓A�j���p�^�[���̐�
		if (m_animeCount <= 4)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (0.2f * m_animeCount);
			}
		}
	}

	m_animeTime++;

	// ���Ԃɉ�����
	if ((m_animeTime % ROTHE_ANIME_INTERVAL) == 0)
	{
		if (m_animeCount >= 0)
		{
			if (m_animeCount == 4)
			{
				m_animeCount = 0;
				m_animeTime = 0;
				
				if (m_animeNumber == 4)
				{
					m_animeEnd = true;
					m_animeNumber = 0;
				}
				
				m_animeNumber++;
			}
			else
			{
				m_animeCount++;
			}
		}
	}

	m_rotheCircleTex.RenderTex(drawEffect);
}
