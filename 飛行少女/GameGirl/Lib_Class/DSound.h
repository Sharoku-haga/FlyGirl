/*
*@file DSound.h
*
*/
#ifndef DSOUND_H
#define DSOUND_H

#include <dSound.h>

//DirectSound�̃C���^�[�t�F�C�X���쐬�A�擾����N���X
class DSound
{
private:
	//DirectSound�̃C���^�[�t�F�C�X
	IDirectSound8 *m_pDSound8;

public:
	//�R���X�g���N�^
	DSound();
	//�f�X�g���N�^
	~DSound();

	////Singleton�p�^�[��
	static DSound& GetInstance()
	{
		static DSound IDirectSound8;

		return IDirectSound8;
	}

	//�C���^�[�t�F�C�X��������
	void InitDSound(HWND hWnd);

	//�C���^�[�t�F�C�X�̎擾
	IDirectSound8* GetInterface();
};


#endif