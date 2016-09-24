/**
*@file InputKey.h
*
*
*/
#ifndef INPUT_KEY_H
#define INPUT_KEY_H
#include <dinput.h>
/**
*
*キーに関するクラス
*
*/
enum  KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	ESCAPE,
	SHIFT,
	SPACE,
	KEYMAX
};

enum KEYSTATE
{
	OFF,/**<キーを離した状態が続いている*/
	ON,/**<キーを押した状態が続いている*/
	RELEASE,/**<キーを離す*/
	PUSH/**<キーを押す*/
};

class InputKey
{

private:
	//キーボードデバイス格納用
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	
	//キーの状態格納する変数
	int m_PreKey[KEYMAX];

public:
	//DIKを格納する変数
	BYTE m_diks[256];
	//キーの種類を格納する変数
	KEYSTATE m_Key[KEYMAX];

	//コンストラクタ
	InputKey();
	//デストラクタ
	~InputKey();

	//Singletonパターン
	static InputKey& GetInstance()
	{
		static InputKey ControlKey;

		return ControlKey;
	}

	//キーの更新
	void UpdateKey();

	//キーの状態を確認する関数
	void KeyCheck(BYTE* DIK, KEYKIND st);

};



#endif