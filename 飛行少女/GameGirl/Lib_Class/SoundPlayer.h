/**
*@file SoundPlayer.h
*
*
*/
#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <windows.h>
#include <dSound.h>
#include"Dsound.h"


//���y�̍Đ��`��
enum SOUNDMODE
{
	Play,
	PlayLoop,
	Stop,
	Reset,
	Stop_Reset,
	Reset_Play
};


//���y���Ǘ�����N���X
class SoundPlayer
{
private:
	//DirectSound�̃C���^�[�t�F�C�X
	IDirectSound8 *m_pDSound8;

	//�Ȃ��i�[����o�b�t�@
	IDirectSoundBuffer8 *m_pDSBuffer;

	//WAVE�t�@�C���I�[�v���֐�
	bool OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize);

public:
	//�R���X�g���N�^
	SoundPlayer();
	//�f�X�g���N�^
	~SoundPlayer();

	//���y��ǂݍ��ފ֐�
	HRESULT LoadSound(TCHAR* filepath);

	//���y�Đ����[�h
	void SoundMode(SOUNDMODE sMode);

};


#endif