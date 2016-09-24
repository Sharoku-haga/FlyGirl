/**
*@file GamePlayer.h
*@brief �Q�[���v���C���[�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*2016/08/20����
*/
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include"LibClass.h"
#include"CommonItems.h"
#include"PlayerBulletManager.h"
#include "Collision.h"
#include "PlayerEffectManager.h"

/**�v���C���[x�����ʒu*/
#define P_POSX_INITVAL 445.f
/**�v���C���[y�����ʒu*/
#define P_POSY_INITVAL 750.f
/**�v���C���[�������C�t*/
#define LIFE_INITVAL 3

/**�v���C���[�̈ړ����x*/
#define P_MOVE_SPEED_DEFAULT 10.f
/**Shift�L�[��������Ԃ̃v���C���[�̈ړ����x*/
#define P_MOVE_SPEED_SHIFT 5.f

/**�v���C���[�e�N�X�`���[��tu�l*/
#define PLAYER_TEX_TU 0.083f
/**�v���C���[�e�N�X�`���[��tv�l*/
#define PLAYER_TEX_TV 0.25f
/**�v���C���[�A�j���[�V�����p�^�[����*/
#define PLAYER_ANIME_PATTERN 2
/**�v���C���[�A�j���[�V�����Ԋu*/
#define PLAYER_ANIME_INTERVAL 20

/**
*�v���C���[���Ǘ�����N���X<br>
*
*/
class GamePlayer
{
private:

	/**�v���C���[�̏��*/
	enum State
	{
		NORMAL,		//!<�ʏ���
		BOM,		//!<�{�����g�p
		HIT,		//!<�����ɓ����������
		INVINCIBLE,	//!<������̖��G�^�C��
		DEATH		//!<���C�t�O
	};

	/**����L�[*/
	InputKey m_gameKey;

	/**�v���C���[�̃e�N�X�`���[*/
	Texture m_playerTex;

	/**�ᑬ���[�h�p�e�N�X�`���[*/
	Texture m_slowModeTex;

	/**�v���C���[�̍��W*/
	D3DXVECTOR2 m_playerPos;

	/**�v���C���[�ړ����x*/
	FLOAT m_moveSpeed;

	/**�v���C���[�̒e���Ǘ�����I�u�W�F�N�g*/
	PlayerBulletManager m_playerBulletManager;

	/**�Փ˔���*/
	Collision* m_collision;

	/**�v���C���[�֘A�̃G�t�F�N�g*/
	PlayerEffectManager m_effectManager;

	/**�v���C���[�̃��C�t*/
	int m_playerLife;

	/**�v���C���[�A�j���̃t���[����*/
	int m_animePattern;

	/**�v���C���[�A�j���̃��o�[�X�t���O*/
	bool m_animeReverse;

	/**�v���C���[�̏��*/
	GamePlayer::State m_playerState;

public:

	// �R���X�g���N�^
	GamePlayer();

	// �f�X�g���N�^
	~GamePlayer();

	// �R���g���[���֐�
	bool Control();

	// �v���C���[�̃L�[����
	void KeyControl();

	// �`��֘A���܂Ƃ߂��֐�
	void Draw();

	// �v���C���[��`�悷��֐�
	void DrawNormal();

	// �ᑬ���[�h�ɂ�����摜��`�悷��֐�
	void DrawSlowMode();

};



#endif
