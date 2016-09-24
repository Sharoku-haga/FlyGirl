/**
*@file RotheCircle.h
*@brief ��]����~�̃G�t�F�N�g�N���X�̃w�b�_�[�t�@�C��
*@author haga
*@data 2016/09/16
*
*/
#ifndef ROTHE_CIRCLE_H
#define ROTHE_CIRCLE_H

/**��]�G�t�F�N�g�̃e�N�X�`���[�T�C�Y*/
#define ROTHE_TEXSIZE 108.f
/**��]�̃G�t�F�N�g�̃A�j���Ԋu*/
#define ROTHE_ANIME_INTERVAL 5

#include "Effect.h"
class RotheCircle :public Effect
{
private:
	/**�e�N�X�`���[���i�[����ϐ�*/
	static Texture m_rotheCircleTex;
	
public:
	/**�R���X�g���N�^*/
	RotheCircle();

	/**�f�X�g���N�^*/
	~RotheCircle();

	/**�`��֐�*/
	virtual void Draw();
};

#endif	// ROTHE_CIRCLE_H
