/**
*@file MyLogo.h
*@brief ���S�̃R���g���[����`����Ǘ�����N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef MY_LOGO_H
#define MY_LOGO_H

#include"LibClass.h"


/**
*���S�̕`���R���g���[�����Ǘ�����N���X
*
*/
class MyLogo
{
private:
	//���S�V�[���̃e�N�X�`�����Ǘ�
	Texture m_Logo;

public:
	//�R���X�g���N�^
	MyLogo();
	//�f�X�g���N�^
	~MyLogo();

	//�`��֐�
	void Draw();
};



#endif