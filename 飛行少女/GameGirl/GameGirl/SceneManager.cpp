/**
*@file SceneManager.cpp
*@brief シーンマネージャークラスのcppファイル
*@author　芳我貴之
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"SceneManager.h"
#include"SceneFactory.h"


// コンストラクタ
SceneManager::SceneManager()
{
	m_pScene = nullptr;
	m_GraphicDevice = &GraphicsD3D::GetInstance();

	m_currentSceneID = Logo_scene;
#ifdef DEBUG

	m_nextSceneID = Game_scene;

#else

	m_nextSceneID = Logo_scene;
#endif

	m_state = Scene_Create;
	m_gameEnd = false;
}

// デストラクタ
SceneManager:: ~SceneManager()
{
	if (m_pScene != nullptr)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}
}

// ゲームを全体の動きや描画を総括する関数
bool SceneManager::RunGame()
{

	Control();

	m_GraphicDevice->StartRender(D3DFVF_CUSTOMVERTEX);

	Render();

	m_GraphicDevice->EndRender();

	return m_gameEnd;
}

// シーンマネージャーのコントロール関数
void SceneManager::Control()
{
	if (m_pScene == nullptr)
	{
		m_currentSceneID = m_nextSceneID;
		if (m_currentSceneID == End_scene)
		{
			m_gameEnd = true;

			return;
		}
	}

	// シーンの状態を確認し、処理を行う
	switch (m_state)
	{
	case Scene_Create:
		// シーンIDをもとにシーンを生成する
		m_pScene = SceneFactory::Instance().CreateScene(m_currentSceneID);

		m_state = Scene_Run;
		break;

	case Scene_Run:
		// シーンIDをチェックして現在のシーンIDと違うなら現在のシ-ンを終わらせる
		if ((m_nextSceneID = m_pScene->Control()) != m_currentSceneID)
		{
			m_state = Scene_End;
		}

		break;

	case Scene_End:

		delete m_pScene;
		m_pScene = nullptr;

		// 次のシーンを作成できる状態にする
		m_state = Scene_Create;

		break;
	}

	return;
}

// シーンマネージャーの描画関数
void SceneManager::Render()
{
	if (m_state == Scene_Run)
	{
		m_pScene->Draw();
		
		return;
	}
	else
	{
		return;
	}
}

