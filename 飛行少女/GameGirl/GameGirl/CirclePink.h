/**
*@file CirclePink.h
*@brief �s���N�̉~�̃G�t�F�N�g�N���X�̃w�b�_�[�t�@�C��
*@author haga
*@data 2016/09/14
*/
#ifndef CIRCLE_PINK_H
#define CIRCLE_PINK_H

/**�T�[�N���̃A�j���Ԋu*/
#define CIRCLE_P_INTERVAL 2

/**�T�[�N���G�t�F�N�g�T�C�Y*/
#define CIRCLE_P_TEXSIZE 180.f

#include "Effect.h"

/**
*�s���N�̉~�̃G�t�F�N�g�N���X(�v���C���[���q�b�g�����Ƃ��̃G�t�F�N�g)<br>
*
*/
class CirclePink :public Effect
{
private:

	/**�G�t�F�N�g�e�N�X�`���[*/
	static Texture m_circleEffectTex;

public:
	/**�R���X�g���N�^*/
	CirclePink();

	/**�f�X�g���N�^*/
	virtual~CirclePink();

	/**�`��֐�*/
	virtual void Draw();
};

#endif // CIRCLE_PINK_H