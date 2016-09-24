/**
*@file SceneManager.h
*@brief シーンマネージャークラスのヘッダファイル
*@author　芳我貴之
*
*/
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"

/**デバック用マクロ<br>*/
//#define DEBUG

/**
*シーンを管理するクラス
*
*/

class SceneManager
{
	/**シーンの状態*/
	enum SceneState
	{
		Scene_Create,			//!<生成
		Scene_Run,				//!<実行
		Scene_End				//!<終了
	};

private:
	/**シーンクラス*/
	Scene* m_pScene;

	/**グラフィックデバイス*/
	GraphicsD3D* m_GraphicDevice;

	/**現在のシーンIDを格納する変数*/
	SceneID m_currentSceneID;

	/**次のシーンIDを格納する変数*/
	SceneID m_nextSceneID;

	/**シーンの状態確認変数*/
	SceneState m_state;

	/**ゲームエンドフラグ*/
	bool m_gameEnd;

public:

	//コンストラクタ
	SceneManager();
	//デストラクタ
	~SceneManager();

	//ゲームを全体の動きを総括する関数
	bool RunGame();
	//コントロール関数
	void Control();
	//描画関数
	void Render();

};


#endif	// SCENE_MANAGER_H