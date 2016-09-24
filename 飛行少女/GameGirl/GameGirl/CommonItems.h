/**
*@file CommonItems.h
*@brief �t�@�C���̋��ʎ���(define�Ȃ�)���܂Ƃ߂��w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef COMMON_ITEMS_H
#define COMMON_ITEMS_H


//------------------------------------------------------
//						�`��֘A
//------------------------------------------------------

/**2D�ɂ����钸�_��*/
#define VERTEX_NUMBER 4
/**�e�N�X�`���[�X�P�[���̊�{�l<br>*/
#define TEXSIZE 64.f


//------------------------------------------------------
//					��ʃT�C�Y�֘A
//------------------------------------------------------

//�E�B���h�E��
#define WINDOW_W 1280
//�E�B���h�E����(�{����960)
#define WINDOW_H 960

//�Q�[���X�e�[�W�̕�
#define GAMESTAGE_W 770.f
//�Q�[���X�e�[�W�̍���
#define GAMESTAGE_H 900.f

/**�Q�[���X�e�[�W��x�����ʒu*/
#define GAMESTAGE_POS_X 60.f
/**�Q�[���X�e�[�W��y�����ʒu*/
#define GAMESTAGE_POS_Y 30.f




//-------------------------------------------------------
//					�Q�[���֘A
//-------------------------------------------------------

/**�v���C���[�̗L���͈�(�����蔻��l)*/
#define PLAYER_RANGE ((TEXSIZE / 2) - 1.f)

/**
*�V�[����ID
*/
enum SceneID
{
	Logo_scene,
	Title_scene,
	Game_scene,
	End_scene
};


/*�G�̃p�^�[����ID**/
enum EnemyPatternID
{
	Enemy_patternA,		/**�G�̏o���p�^�[��A*/
	Enemy_patternB,		/**�G�̏o���p�^�[��B*/
	Enemy_patternBOSS,	/**�G�̏o���p�^�[���{�X*/
	EnemyEnd			/**�p�^�[���I��*/
};


#endif // CommonItems.h