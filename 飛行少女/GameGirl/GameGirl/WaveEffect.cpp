/**
*@file WaveEffect.cpp
@brief �g�`�̃G�t�F�N�g�������N���X��cpp�t�@�C��
*@autor haga
*/
#include "WaveEffect.h"

Texture WaveEffect::m_waveEffectTex;

/**�R���X�g���N�^*/
WaveEffect::WaveEffect()
{
	//�e�N�`���[��ǂݍ���
	if (WaveEffect::m_waveEffectTex.GetStateTex() == NULL)
	{
		WaveEffect::m_waveEffectTex.GetDevice();
		WaveEffect::m_waveEffectTex.LoadTexEx("Picture\\GameScene\\Effect\\wave01.png", 255, 0, 0, 0, false);
	}
}

/**�f�X�g���N�^*/
WaveEffect::~WaveEffect()
{

}

/**�`��֐�*/
void WaveEffect::Draw()
{
	//�g�`�G�t�F�N�g�̒��_���
	CUSTOMVERTEX waveEffect[]
	{
		{ -EFFECT_TEXSIZE / 2.0f, -EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,           0.0f,           0.0f },
		{  EFFECT_TEXSIZE / 2.0f, -EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, WAVE_EFFECT_TU,           0.0f },
		{  EFFECT_TEXSIZE / 2.0f,  EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, WAVE_EFFECT_TU, WAVE_EFFECT_TV },
		{ -EFFECT_TEXSIZE / 2.0f,  EFFECT_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF,           0.0f, WAVE_EFFECT_TV },
	};

	//�`��p�̋�̊�
	CUSTOMVERTEX drawEffect[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER;i++)
	{
		drawEffect[i] = waveEffect[i];

		drawEffect[i].x += m_effctPos.x;
		drawEffect[i].y += m_effctPos.y;
	}

	//�A�j���[�V�����̕ω�
	if (m_animeCount > 0)
	{
		if (m_animeCount < WAVE_ANIME_PATTERN)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tu += (WAVE_EFFECT_TU * m_animeCount);
			}
		}
		else
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawEffect[i].tv += WAVE_EFFECT_TV;
				drawEffect[i].tu += (WAVE_EFFECT_TU  * (m_animeCount - WAVE_ANIME_PATTERN));
			}
		}
	}

	m_animeTime++;

	// ���Ԃɉ�����
	if ((m_animeTime % WAVE_ANIME_INTERVAL) == 0)
	{
		if (m_animeCount >= 0)
		{
			if (m_animeCount == ((WAVE_ANIME_PATTERN * 2) - 1))
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

	m_waveEffectTex.RenderTex(drawEffect);

}
