/**
*@file PlayerEffectManager.cpp
*@brief �v���C���[�̃G�t�F�N�g���Ǘ�����N���X��cpp
*@author haga
*@data 2016/09/14
*/
#include "PlayerEffectManager.h"

// �R���X�g���N�^
PlayerEffectManager::PlayerEffectManager()
{
}

// �f�X�g���N�^
PlayerEffectManager::~PlayerEffectManager()
{
}

// �q�b�g�G�t�F�N�g�̏�Ԃ��m�F
bool PlayerEffectManager::GetStateHitEffect()
{
	// �A�j�����I����Ă���Ȃ�true��������
	return m_hitEffect.GetAnimeState();
}

// �q�b�g�G�t�F�N�g��`��
void PlayerEffectManager::DrawHitEffect()
{
	// �G�t�F�N�g��`��
	m_hitEffect.Draw();
}

// �q�b�g�G�t�F�N�g�̍��W���擾
void PlayerEffectManager::SetHitEffectPos(const D3DXVECTOR2* _objPos)
{
	m_hitEffect.SetEffectPos((*_objPos));
}

// ���G���Ԃ̃G�t�F�N�g�̏�Ԃ��擾
bool PlayerEffectManager::GetStateInviEffect()
{
	return m_InviEffect.GetAnimeState();
}

// ���G���Ԃ̃G�t�F�N�g��`��
void PlayerEffectManager::DrawInviEffect(const D3DXVECTOR2* _objPos)
{
	// ���W���擾
	m_InviEffect.SetEffectPos((*_objPos));

	// �`��
	m_InviEffect.Draw();
}

