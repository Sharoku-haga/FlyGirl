/**
*@file Effect.h
*@brief �G�t�F�N�g�̊�{�N���X(���ۃN���X)
*@autor haga
*
*/
#ifndef EFFECT_H
#define EFFECT_H

/**�G�t�F�N�g�̃e�N�X�`���[�T�C�Y*/
#define EFFECT_TEXSIZE 128.f

#include"CommonItems.h"
#include"Texture.h"

/**
*�G�t�F�N�g�̃N���X.
*
*/
class Effect
{

protected:

	/**���ʂ̍��W*/
	D3DXVECTOR2 m_effctPos;

	/**�A�j���[�V�����I���̃t���O*/
	bool m_animeEnd;

	/**�A�j���[�V��������*/
	int m_animeTime;

	/**�A�j���[�V�����̃p�^�[�����J�E���g����ϐ�*/
	int m_animeCount;

	/*�A�j���[�V�����̐����i�[����ϐ�**/
	int m_animeNumber;

public:

	/**�R���X�g���N�^*/
	Effect()
	{
		m_animeNumber = 0;
		m_animeEnd = false;
		m_animeTime = 0;
		m_animeCount = 0;
	};

	/**�f�X�g���N�^*/
	virtual~Effect(){};

	/**�`��֐�*/
	virtual void Draw(){};

	/**�A�j���[�V�����̏�Ԃ��m�F*/
	bool GetAnimeState()
	{ 
		if (m_animeEnd)
		{
			m_animeEnd = false;
			
			return true;
		}
		else
		{
			return false;
		}
	};

	/**���W���Z�b�g����*/
	void SetEffectPos(D3DXVECTOR2 _objPos){ m_effctPos = _objPos; }
};

#endif