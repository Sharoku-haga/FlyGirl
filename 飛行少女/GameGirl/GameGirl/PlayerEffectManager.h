/**
*@file PlayerEffectManager.h
*@brief プレイヤーのエフェクトを管理するクラスのh
*@author haga
*@data 2016/09/14
*/
#ifndef PLAYER_EFFECT_MANAGER_H 
#define PLAYER_EFFECT_MANAGER_H

#include "CirclePink.h"
#include "RotheCircle.h"

/**
*プレイヤーのエフェクトを管理するクラス
*
*/
class PlayerEffectManager
{
private:

	/**何かと衝突したとき（ヒット）のエフェクト*/
	CirclePink m_hitEffect;

	/**無敵時間中のエフェクト*/
	RotheCircle m_InviEffect;

public:
	/**コンストラクタ*/
	PlayerEffectManager();

	/**デストラクタ*/
	~PlayerEffectManager();

	/**ヒットエフェクトの状態を確認*/
	bool GetStateHitEffect();

	/**ヒットエフェクトを描画*/
	void DrawHitEffect();

	/**ヒットエフェクトの座標を取得*/
	void SetHitEffectPos(const D3DXVECTOR2* _objPos);

	/**無敵エフェクトの状態を確認*/
	bool GetStateInviEffect();

	/**無敵エフェクトを描画*/
	void DrawInviEffect(const D3DXVECTOR2* _objPos);


};

#endif	// PLAYER_EFFECT_MANAGER_H