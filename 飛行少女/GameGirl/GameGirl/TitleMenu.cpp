/**
*@file TitleMenu.h
*@brief タイトルメニュークラスのヘッダファイル
*@author　芳我貴之
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"TitleMenu.h"

// コンストラクタ
TitleMenu::TitleMenu()
{
	m_currentMenu = START;

	// 座標をいれる
	for (int i = 0; i < MENU_MAX;i++)
	{
		m_menuPos[i].x = 430.f;
		m_menuPos[i].y = 500.f + (100.f*i);
	}

	m_animePattern = 0;
	m_animeTime = 0;

	// テクスチャー読み込み
	m_menuButton[START].LoadTex("Picture\\TitleScene\\MenuGameStart.png");
	m_menuButton[SCORE].LoadTex("Picture\\TitleScene\\MenuGameScore.png");
	m_menuButton[END].LoadTex("Picture\\TitleScene\\MenuGameEnd.png");
	m_selectIcon.LoadTexEx("Picture\\TitleScene\\SelectIcon.png", 255, 0, 0, 0, false);

}

// デストラクタ
TitleMenu::~TitleMenu()
{

}

// コントロール関数
SceneID TitleMenu::Control()
{
	m_gameKey.UpdateKey();
	// キー状態を確認
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_UP], UP);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_DOWN], DOWN);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_RIGHT], RIGHT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LEFT], LEFT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);

	// キー操作
	if (m_currentMenu != SCORE)
	{
		if (m_gameKey.m_Key[UP] == PUSH && m_currentMenu == END)
		{
			m_currentMenu = SCORE;
		}
		if (m_gameKey.m_Key[DOWN] == PUSH && m_currentMenu == START)
		{
			m_currentMenu = SCORE;
		}
	}
	else
	{
		if (m_gameKey.m_Key[UP] == PUSH)
		{
			m_currentMenu = START;
		}
		if (m_gameKey.m_Key[DOWN] == PUSH)
		{
			m_currentMenu = END;
		}
	}

	if (m_gameKey.m_Key[Z] == PUSH)
	{
		switch (m_currentMenu)
		{
		case START:
			// ゲームシーンに移行
			return Game_scene;

		case SCORE:

			// スコアを表示

		case END:
			// ゲーム終了
			return End_scene;
		}
	}
	
	return Title_scene;
}

// 描画
void TitleMenu::Draw()
{
	// メニューの頂点情報
	CUSTOMVERTEX menuButton[] = {
		{  0.0f,  0.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 0.0f },
		{ 420.f,  0.0f, 0.5f, 1.0f, 0x99FFFFFF, 1.0f, 0.0f },
		{ 420.f, 100.f, 0.5f, 1.0f, 0x99FFFFFF, 1.0f, 1.0f },
		{  0.0f, 100.f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 1.0f }
	};

	// 描画用の空の器
	CUSTOMVERTEX drawVertex[MENU_MAX][VERTEX_NUMBER];

	for (int i = 0; i < MENU_MAX;i++)
	{
		for (int j = 0; j < VERTEX_NUMBER;j++)
		{
			drawVertex[i][j] = menuButton[j];
			drawVertex[i][j].x += m_menuPos[i].x;
			drawVertex[i][j].y += m_menuPos[i].y;
			
			// 現在選んでいるメニューはアルファ値をあげるＭＡＸにする
			if (m_currentMenu == i)
			{
				drawVertex[i][j].color = 0xFFFFFFFF;
			}
		}

		m_menuButton[i].RenderTex(drawVertex[i]);
	}

	DrawIcon();

}

// アイコンの描画(アニメーション管理もここで行う)
void TitleMenu::DrawIcon()
{
	// メニューアイコンの頂点情報
	CUSTOMVERTEX selectIcon[]
	{
		{ -MENU_ICON_TEXSIZE / 2.0f, -MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  MENU_ICON_TEXSIZE / 2.0f, -MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.0f },
		{  MENU_ICON_TEXSIZE / 2.0f,  MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.5f },
		{ -MENU_ICON_TEXSIZE / 2.0f,  MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.5f },
	};

	// 描画用の空の器
	CUSTOMVERTEX drawVertex[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawVertex[i] = selectIcon[i];
		drawVertex[i].x += m_menuPos[m_currentMenu].x;
		drawVertex[i].y += m_menuPos[m_currentMenu].y;

		// メニューボタンからアイコンをずらす
		drawVertex[i].x -= MENU_ICON_TEXSIZE / 2.0f;
		drawVertex[i].y += MENU_ICON_TEXSIZE / 2.0f;
		// 微調整
		drawVertex[i].y +=10.f;
	}

	// アニメーション
	// 0.2fは1コマのtu値の大きさ、0.5fは1コマのtv値の大きさ
	// 5はアニメのコマのtu列のMAX値、2はアニメのコマのtv列のMAX値
	if (m_animePattern > 0)
	{
		if (m_animePattern < 5)
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawVertex[i].tu += (0.2f * m_animePattern);
			}
		}
		else
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				drawVertex[i].tv += 0.5f;
				drawVertex[i].tu += (0.2f * (m_animePattern - 5));
			}
		}
	}

	m_animeTime++;	// アニメーション時間をカウント

	if ((m_animeTime % ICON_ANIME_INTERVAL) == 0)
	{
		// アニメのコマがMAXになるまでカウントし、MAXになったら0にリセット(9はMAX値)
		if (m_animePattern == 9)
		{
			m_animePattern = 0;
			m_animeTime = 0;
		}
		else
		{
			m_animePattern++;
		}
	}
	m_selectIcon.RenderTex(drawVertex);
}