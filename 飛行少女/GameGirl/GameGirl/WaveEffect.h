/**
*@file WaveEffect.h
@brief �g�`�̃G�t�F�N�g�������N���X�̃w�b�_�[�t�@�C��
*@autor haga
*/
#ifndef WAVE_EFFECT_H
#define WAVE_EFFECT_H

/**�g�`�ɃG�t�F�N�g��tu�l*/
#define WAVE_EFFECT_TU 0.2f
/**�g�`�ɃG�t�F�N�g��tv�l*/
#define WAVE_EFFECT_TV 0.5f

/**�g�`�̃G�t�F�N�g�̃A�j���p�^�[���P��ڂ̐�*/
#define WAVE_ANIME_PATTERN 5

/**�g�`�̃G�t�F�N�g�̃A�j������*/
#define WAVE_ANIME_INTERVAL 1

#include "Effect.h"

/**
*�~�^�̔g�`�̃G�t�F�N�g�������N���X
*
*/
class WaveEffect :public Effect
{
private:

	/**t�e�N�X�`���[���i�[����ϐ�*/
	static Texture m_waveEffectTex;

public:

	/**�R���X�g���N�^*/
	WaveEffect();
	/**�f�X�g���N�^*/
	virtual~WaveEffect();

	/**�`��֐�*/
	virtual void Draw();

};


#endif
