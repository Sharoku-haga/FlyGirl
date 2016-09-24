/**
*@file TitleMenu.h
*@brief タイトルメニュークラスのヘッダファイル
*@author　芳我貴之
*2016/08/19 
*/
#ifndef TITLE_MENU_H
#define TITLE_MENU_H


/**アイコンのテクスチャーサイズ*/
#define MENU_ICON_TEXSIZE 80.f

/**アイコンのアニメ時間*/
#define ICON_ANIME_INTERVAL 4


#include"LibClass.h"
#include"CommonItems.h"
/**
*タイトルメニューを管理するクラス
*
*/
class TitleMenu
{
	/**メニューボタンの種類*/
	enum MenuButton
	{
		START,
		SCORE,
		END,
		MENU_MAX
	};

private:
	/**操作キー*/
	InputKey m_gameKey;

	/**現在選んでいるメニュー*/
	MenuButton m_currentMenu;

	/**メニューの座標*/
	D3DXVECTOR2 m_menuPos[MENU_MAX];

	/**メニューボタンのテクスチャーを格納する変数*/
	Texture m_menuButton[MENU_MAX];

	/**メニューのセレクアイコンのテクスチャーを格納する変数*/
	Texture m_selectIcon;

	/**メニューアイコンのアニメパターンカウント数*/
	int m_animePattern;

	/**メニューアイコンのアニメ時間をカウントする変数*/
	int m_animeTime;

public:
	/**コンストラクタ*/
	TitleMenu();

	/**デストラクタ*/
	~TitleMenu();

	/**メニューコントロール関数*/
	SceneID Control();

	/**描画*/
	void Draw();

	/**アイコンの描画*/
	void DrawIcon();

};



#endif	// TITLE_MENU_H