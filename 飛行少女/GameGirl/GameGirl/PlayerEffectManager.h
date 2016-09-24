/**
*@file PlayerEffectManager.h
*@brief �v���C���[�̃G�t�F�N�g���Ǘ�����N���X��h
*@author haga
*@data 2016/09/14
*/
#ifndef PLAYER_EFFECT_MANAGER_H 
#define PLAYER_EFFECT_MANAGER_H

#include "CirclePink.h"
#include "RotheCircle.h"

/**
*�v���C���[�̃G�t�F�N�g���Ǘ�����N���X
*
*/
class PlayerEffectManager
{
private:

	/**�����ƏՓ˂����Ƃ��i�q�b�g�j�̃G�t�F�N�g*/
	CirclePink m_hitEffect;

	/**���G���Ԓ��̃G�t�F�N�g*/
	RotheCircle m_InviEffect;

public:
	/**�R���X�g���N�^*/
	PlayerEffectManager();

	/**�f�X�g���N�^*/
	~PlayerEffectManager();

	/**�q�b�g�G�t�F�N�g�̏�Ԃ��m�F*/
	bool GetStateHitEffect();

	/**�q�b�g�G�t�F�N�g��`��*/
	void DrawHitEffect();

	/**�q�b�g�G�t�F�N�g�̍��W���擾*/
	void SetHitEffectPos(const D3DXVECTOR2* _objPos);

	/**���G�G�t�F�N�g�̏�Ԃ��m�F*/
	bool GetStateInviEffect();

	/**���G�G�t�F�N�g��`��*/
	void DrawInviEffect(const D3DXVECTOR2* _objPos);


};

#endif	// PLAYER_EFFECT_MANAGER_H