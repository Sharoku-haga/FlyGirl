/**
*@file GamePlayer.h
*@brief ゲームプレイヤークラスのヘッダファイル
*@author　芳我貴之
*2016/08/20制作
*/
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBulletManager.h"
#include "Collision.h"
#include "PlayerEffectManager.h"

/**プレイヤーx初期位置*/
#define P_POSX_INITVAL 445.f
/**プレイヤーy初期位置*/
#define P_POSY_INITVAL 750.f
/**プレイヤー初期ライフ*/
#define LIFE_INITVAL 3

/**プレイヤーの移動速度*/
#define P_MOVE_SPEED_DEFAULT 10.f
/**Shiftキー押した状態のプレイヤーの移動速度*/
#define P_MOVE_SPEED_SHIFT 5.f

/**プレイヤーテクスチャーのtu値*/
#define PLAYER_TEX_TU 0.083f
/**プレイヤーテクスチャーのtv値*/
#define PLAYER_TEX_TV 0.25f
/**プレイヤーアニメーションパターン数*/
#define PLAYER_ANIME_PATTERN 2
/**プレイヤーアニメーション間隔*/
#define PLAYER_ANIME_INTERVAL 20

/**
*プレイヤーを管理するクラス<br>
*
*/
class GamePlayer
{
private:

	/**プレイヤーの状態*/
	enum State
	{
		NORMAL,		//!<通常状態
		BOM,		//!<ボムを使用
		HIT,		//!<何かに当たった状態
		INVINCIBLE,	//!<復活後の無敵タイム
		DEATH		//!<ライフ０
	};

	/**操作キー*/
	InputKey m_gameKey;

	/**プレイヤーのテクスチャー*/
	Texture m_playerTex;

	/**低速モード用テクスチャー*/
	Texture m_slowModeTex;

	/**プレイヤーの座標*/
	D3DXVECTOR2 m_playerPos;

	/**プレイヤー移動速度*/
	FLOAT m_moveSpeed;

	/**プレイヤーの弾を管理するオブジェクト*/
	PlayerBulletManager m_playerBulletManager;

	/**衝突判定*/
	Collision* m_collision;

	/**プレイヤー関連のエフェクト*/
	PlayerEffectManager m_effectManager;

	/**プレイヤーのライフ*/
	int m_playerLife;

	/**プレイヤーアニメのフレーム数*/
	int m_animePattern;

	/**プレイヤーアニメのリバースフラグ*/
	bool m_animeReverse;

	/**プレイヤーの状態*/
	GamePlayer::State m_playerState;

public:

	// コンストラクタ
	GamePlayer();

	// デストラクタ
	~GamePlayer();

	// コントロール関数
	bool Control();

	// プレイヤーのキー操作
	void KeyControl();

	// 描画関連をまとめた関数
	void Draw();

	// プレイヤーを描画する関数
	void DrawNormal();

	// 低速モードにおける画像を描画する関数
	void DrawSlowMode();

};



#endif
