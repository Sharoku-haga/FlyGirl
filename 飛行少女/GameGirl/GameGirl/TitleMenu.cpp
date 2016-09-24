/**
*@file TitleMenu.h
*@brief �^�C�g�����j���[�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"TitleMenu.h"

// �R���X�g���N�^
TitleMenu::TitleMenu()
{
	m_currentMenu = START;

	// ���W�������
	for (int i = 0; i < MENU_MAX;i++)
	{
		m_menuPos[i].x = 430.f;
		m_menuPos[i].y = 500.f + (100.f*i);
	}

	m_animePattern = 0;
	m_animeTime = 0;

	// �e�N�X�`���[�ǂݍ���
	m_menuButton[START].LoadTex("Picture\\TitleScene\\MenuGameStart.png");
	m_menuButton[SCORE].LoadTex("Picture\\TitleScene\\MenuGameScore.png");
	m_menuButton[END].LoadTex("Picture\\TitleScene\\MenuGameEnd.png");
	m_selectIcon.LoadTexEx("Picture\\TitleScene\\SelectIcon.png", 255, 0, 0, 0, false);

}

// �f�X�g���N�^
TitleMenu::~TitleMenu()
{

}

// �R���g���[���֐�
SceneID TitleMenu::Control()
{
	m_gameKey.UpdateKey();
	// �L�[��Ԃ��m�F
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_UP], UP);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_DOWN], DOWN);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_RIGHT], RIGHT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_LEFT], LEFT);
	m_gameKey.KeyCheck(&m_gameKey.m_diks[DIK_Z], Z);

	// �L�[����
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
			// �Q�[���V�[���Ɉڍs
			return Game_scene;

		case SCORE:

			// �X�R�A��\��

		case END:
			// �Q�[���I��
			return End_scene;
		}
	}
	
	return Title_scene;
}

// �`��
void TitleMenu::Draw()
{
	// ���j���[�̒��_���
	CUSTOMVERTEX menuButton[] = {
		{  0.0f,  0.0f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 0.0f },
		{ 420.f,  0.0f, 0.5f, 1.0f, 0x99FFFFFF, 1.0f, 0.0f },
		{ 420.f, 100.f, 0.5f, 1.0f, 0x99FFFFFF, 1.0f, 1.0f },
		{  0.0f, 100.f, 0.5f, 1.0f, 0x99FFFFFF, 0.0f, 1.0f }
	};

	// �`��p�̋�̊�
	CUSTOMVERTEX drawVertex[MENU_MAX][VERTEX_NUMBER];

	for (int i = 0; i < MENU_MAX;i++)
	{
		for (int j = 0; j < VERTEX_NUMBER;j++)
		{
			drawVertex[i][j] = menuButton[j];
			drawVertex[i][j].x += m_menuPos[i].x;
			drawVertex[i][j].y += m_menuPos[i].y;
			
			// ���ݑI��ł��郁�j���[�̓A���t�@�l��������l�`�w�ɂ���
			if (m_currentMenu == i)
			{
				drawVertex[i][j].color = 0xFFFFFFFF;
			}
		}

		m_menuButton[i].RenderTex(drawVertex[i]);
	}

	DrawIcon();

}

// �A�C�R���̕`��(�A�j���[�V�����Ǘ��������ōs��)
void TitleMenu::DrawIcon()
{
	// ���j���[�A�C�R���̒��_���
	CUSTOMVERTEX selectIcon[]
	{
		{ -MENU_ICON_TEXSIZE / 2.0f, -MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  MENU_ICON_TEXSIZE / 2.0f, -MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.0f },
		{  MENU_ICON_TEXSIZE / 2.0f,  MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.2f, 0.5f },
		{ -MENU_ICON_TEXSIZE / 2.0f,  MENU_ICON_TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.5f },
	};

	// �`��p�̋�̊�
	CUSTOMVERTEX drawVertex[VERTEX_NUMBER];

	for (int i = 0; i < VERTEX_NUMBER; i++)
	{
		drawVertex[i] = selectIcon[i];
		drawVertex[i].x += m_menuPos[m_currentMenu].x;
		drawVertex[i].y += m_menuPos[m_currentMenu].y;

		// ���j���[�{�^������A�C�R�������炷
		drawVertex[i].x -= MENU_ICON_TEXSIZE / 2.0f;
		drawVertex[i].y += MENU_ICON_TEXSIZE / 2.0f;
		// ������
		drawVertex[i].y +=10.f;
	}

	// �A�j���[�V����
	// 0.2f��1�R�}��tu�l�̑傫���A0.5f��1�R�}��tv�l�̑傫��
	// 5�̓A�j���̃R�}��tu���MAX�l�A2�̓A�j���̃R�}��tv���MAX�l
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

	m_animeTime++;	// �A�j���[�V�������Ԃ��J�E���g

	if ((m_animeTime % ICON_ANIME_INTERVAL) == 0)
	{
		// �A�j���̃R�}��MAX�ɂȂ�܂ŃJ�E���g���AMAX�ɂȂ�����0�Ƀ��Z�b�g(9��MAX�l)
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