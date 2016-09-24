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
*�L�[�Ɋւ���N���X
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
	OFF,/**<�L�[�𗣂�����Ԃ������Ă���*/
	ON,/**<�L�[����������Ԃ������Ă���*/
	RELEASE,/**<�L�[�𗣂�*/
	PUSH/**<�L�[������*/
};

class InputKey
{

private:
	//�L�[�{�[�h�f�o�C�X�i�[�p
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	
	//�L�[�̏�Ԋi�[����ϐ�
	int m_PreKey[KEYMAX];

public:
	//DIK���i�[����ϐ�
	BYTE m_diks[256];
	//�L�[�̎�ނ��i�[����ϐ�
	KEYSTATE m_Key[KEYMAX];

	//�R���X�g���N�^
	InputKey();
	//�f�X�g���N�^
	~InputKey();

	//Singleton�p�^�[��
	static InputKey& GetInstance()
	{
		static InputKey ControlKey;

		return ControlKey;
	}

	//�L�[�̍X�V
	void UpdateKey();

	//�L�[�̏�Ԃ��m�F����֐�
	void KeyCheck(BYTE* DIK, KEYKIND st);

};



#endif