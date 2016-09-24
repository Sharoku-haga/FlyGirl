/**
*@file TitleLogo.h
*@brief �^�C�g�����S�i�w�i�j�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef TITLE_LOGO_H
#define TITLE_LOGO_H

#include"LibClass.h"
#include"CommonItems.h"

/**
*�^�C�g�����S(�w�i)���Ǘ�����N���X<br>
*
*/
class TitleLogo
{
private:

	// �^�C�g�����S�̃e�N�X�`���[���i�[
	Texture m_titleLogoTex;

public:

	// �R���X�g���N�^
	TitleLogo();

	// �f�X�g���N�^
	~TitleLogo();

	// �`��֐�
	void Draw();
};



#endif		// TITLE_LOGO_H