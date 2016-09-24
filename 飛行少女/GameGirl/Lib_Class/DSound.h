/*
*@file DSound.h
*
*/
#ifndef DSOUND_H
#define DSOUND_H

#include <dSound.h>

//DirectSoundのインターフェイスを作成、取得するクラス
class DSound
{
private:
	//DirectSoundのインターフェイス
	IDirectSound8 *m_pDSound8;

public:
	//コンストラクタ
	DSound();
	//デストラクタ
	~DSound();

	////Singletonパターン
	static DSound& GetInstance()
	{
		static DSound IDirectSound8;

		return IDirectSound8;
	}

	//インターフェイスを初期化
	void InitDSound(HWND hWnd);

	//インターフェイスの取得
	IDirectSound8* GetInterface();
};


#endif