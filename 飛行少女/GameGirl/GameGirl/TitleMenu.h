/**
*@file TitleMenu.h
*@brief �^�C�g�����j���[�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/19 
*/
#ifndef TITLE_MENU_H
#define TITLE_MENU_H


/**�A�C�R���̃e�N�X�`���[�T�C�Y*/
#define MENU_ICON_TEXSIZE 80.f

/**�A�C�R���̃A�j������*/
#define ICON_ANIME_INTERVAL 4


#include"LibClass.h"
#include"CommonItems.h"
/**
*�^�C�g�����j���[���Ǘ�����N���X
*
*/
class TitleMenu
{
	/**���j���[�{�^���̎��*/
	enum MenuButton
	{
		START,
		SCORE,
		END,
		MENU_MAX
	};

private:
	/**����L�[*/
	InputKey m_gameKey;

	/**���ݑI��ł��郁�j���[*/
	MenuButton m_currentMenu;

	/**���j���[�̍��W*/
	D3DXVECTOR2 m_menuPos[MENU_MAX];

	/**���j���[�{�^���̃e�N�X�`���[���i�[����ϐ�*/
	Texture m_menuButton[MENU_MAX];

	/**���j���[�̃Z���N�A�C�R���̃e�N�X�`���[���i�[����ϐ�*/
	Texture m_selectIcon;

	/**���j���[�A�C�R���̃A�j���p�^�[���J�E���g��*/
	int m_animePattern;

	/**���j���[�A�C�R���̃A�j�����Ԃ��J�E���g����ϐ�*/
	int m_animeTime;

public:
	/**�R���X�g���N�^*/
	TitleMenu();

	/**�f�X�g���N�^*/
	~TitleMenu();

	/**���j���[�R���g���[���֐�*/
	SceneID Control();

	/**�`��*/
	void Draw();

	/**�A�C�R���̕`��*/
	void DrawIcon();

};



#endif	// TITLE_MENU_H