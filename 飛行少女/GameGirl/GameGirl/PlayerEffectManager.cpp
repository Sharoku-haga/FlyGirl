/**
*@file PlayerEffectManager.cpp
*@brief プレイヤーのエフェクトを管理するクラスのcpp
*@author haga
*@data 2016/09/14
*/
#include "PlayerEffectManager.h"

// コンストラクタ
PlayerEffectManager::PlayerEffectManager()
{
}

// デストラクタ
PlayerEffectManager::~PlayerEffectManager()
{
}

// ヒットエフェクトの状態を確認
bool PlayerEffectManager::GetStateHitEffect()
{
	// アニメが終わっているならtrueをかえす
	return m_hitEffect.GetAnimeState();
}

// ヒットエフェクトを描画
void PlayerEffectManager::DrawHitEffect()
{
	// エフェクトを描画
	m_hitEffect.Draw();
}

// ヒットエフェクトの座標を取得
void PlayerEffectManager::SetHitEffectPos(const D3DXVECTOR2* _objPos)
{
	m_hitEffect.SetEffectPos((*_objPos));
}

// 無敵時間のエフェクトの状態を取得
bool PlayerEffectManager::GetStateInviEffect()
{
	return m_InviEffect.GetAnimeState();
}

// 無敵時間のエフェクトを描画
void PlayerEffectManager::DrawInviEffect(const D3DXVECTOR2* _objPos)
{
	// 座標を取得
	m_InviEffect.SetEffectPos((*_objPos));

	// 描画
	m_InviEffect.Draw();
}

