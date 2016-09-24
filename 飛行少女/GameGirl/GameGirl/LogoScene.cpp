/**
*@file LogoScene.h
*@brief ロゴシーンクラスのヘッダファイル
*@author　芳我貴之
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"LogoScene.h"
#include"MyLogo.h"

//コンストラクタ
LogoScene::LogoScene()
{
	
}

//デストラクタ
LogoScene::~LogoScene()
{

}

//コントロール関数
SceneID LogoScene::Control()
{
	m_gameKey.UpdateKey();

	//キー状態を確認
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);

	//ボタンを押されたらタイトルシーンに移行する
	if (m_gameKey.m_Key[Z] == ON)
	{
		return SceneID::Title_scene;
	}

	return Logo_scene;
}

//描画関数
void LogoScene::Draw()
{
	m_myLogo.Draw();
}