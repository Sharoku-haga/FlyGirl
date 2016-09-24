/**
*@file CommonItems.h
*@brief ファイルの共通事項(defineなど)をまとめたヘッダファイル
*@author　芳我貴之
*
*/
#ifndef COMMON_ITEMS_H
#define COMMON_ITEMS_H


//------------------------------------------------------
//						描画関連
//------------------------------------------------------

/**2Dにおける頂点数*/
#define VERTEX_NUMBER 4
/**テクスチャースケールの基本値<br>*/
#define TEXSIZE 64.f


//------------------------------------------------------
//					画面サイズ関連
//------------------------------------------------------

//ウィンドウ幅
#define WINDOW_W 1280
//ウィンドウ高さ(本来は960)
#define WINDOW_H 960

//ゲームステージの幅
#define GAMESTAGE_W 770.f
//ゲームステージの高さ
#define GAMESTAGE_H 900.f

/**ゲームステージのx初期位置*/
#define GAMESTAGE_POS_X 60.f
/**ゲームステージのy初期位置*/
#define GAMESTAGE_POS_Y 30.f




//-------------------------------------------------------
//					ゲーム関連
//-------------------------------------------------------

/**プレイヤーの有効範囲(当たり判定値)*/
#define PLAYER_RANGE ((TEXSIZE / 2) - 1.f)

/**
*シーンのID
*/
enum SceneID
{
	Logo_scene,
	Title_scene,
	Game_scene,
	End_scene
};


/*敵のパターンのID**/
enum EnemyPatternID
{
	Enemy_patternA,		/**敵の出現パターンA*/
	Enemy_patternB,		/**敵の出現パターンB*/
	Enemy_patternBOSS,	/**敵の出現パターンボス*/
	EnemyEnd			/**パターン終了*/
};


#endif // CommonItems.h