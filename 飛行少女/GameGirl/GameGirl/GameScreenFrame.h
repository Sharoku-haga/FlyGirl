/**
*@file GameScreenFrame.h
*@brief �Q�[����ʂ̘g�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef GAME_SCREEN_FARAME_H
#define GAME_SCREEN_FARAME_H

#include"LibClass.h"
#include"CommonItems.h"

/**
*�Q�[����ʂ̘g���Ǘ�����N���X<br>
*
*/
class GameScreenFrame
{
private:

	//�摜���i�[����ϐ�
	Texture m_screenFarame;

public:

	//�R���X�g���N�^
	GameScreenFrame();

	//�f�X�g���N�^
	~GameScreenFrame();

	//�`��֐�
	void Draw();

};





#endif