/**
*@file CirclePink.cpp 
*@brief �s���N�̉~�̃G�t�F�N�g�N���X
*
*/
#include "CirclePink.h"

// static�֐�
Texture CirclePink::m_circleEffectTex;

// �R���X�g���N�^
CirclePink::CirclePink()
{
	//�e�N�`���[��ǂݍ���
	if (CirclePink::m_circleEffectTex.GetStateTex() == NULL)
	{
		CirclePink::m_circleEffectTex.GetDevice();
		CirclePink::m_circleEffectTex.LoadTexEx("Picture\\GameScene\\Effect\\CirclePink.png", 255, 0, 0, 0, false);
	}
}

// �f�X�g���N�^
CirclePink::~CirclePink()
{
}

// �`��֐�
void CirclePink::Draw()
{
	//�g�`�G�t�F�N�g�̒��_���
	CUSTOMVERTEX circleEffect[]
	{
		{ -CIRCLE_P_TEXSIZE / 2.0f, -CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  CIRCLE_P_TEXSIZE / 2.0f, -CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.0f },
		{  CIRCLE_P_TEXSIZE / 2.0f,  CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 1.0f },
		{ -CIRCLE_P_TEXSIZE / 2.0f,  CIRCLE_P_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// �`��p�̋�̊�
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawEffect[i] = circleEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//�A�j���[�V�����̕ω�
	if (m_animeCount > 0)
	{
		// 4�̓A�j���p�^�[���̐�
		if (m_animeCount <= 4 )
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (0.2f * m_animeCount);
			}
		}
	}

	m_animeTime++;

	// ���Ԃɉ�����
	if ((m_animeTime % CIRCLE_P_INTERVAL) == 0)
		{
			if (m_animeCount >= 0)
			{
				if (m_animeCount == 4)
				{
					m_animeCount = 0;
					m_animeTime = 0;
					m_animeEnd = true;
				}
				else
				{
					m_animeCount++;
				}
			}
		}

	m_circleEffectTex.RenderTex(drawEffect);
	
}
