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


//音楽の再生形式
enum SOUNDMODE
{
	Play,
	PlayLoop,
	Stop,
	Reset,
	Stop_Reset,
	Reset_Play
};


//音楽を管理するクラス
class SoundPlayer
{
private:
	//DirectSoundのインターフェイス
	IDirectSound8 *m_pDSound8;

	//曲を格納するバッファ
	IDirectSoundBuffer8 *m_pDSBuffer;

	//WAVEファイルオープン関数
	bool OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize);

public:
	//コンストラクタ
	SoundPlayer();
	//デストラクタ
	~SoundPlayer();

	//音楽を読み込む関数
	HRESULT LoadSound(TCHAR* filepath);

	//音楽再生モード
	void SoundMode(SOUNDMODE sMode);

};


#endif