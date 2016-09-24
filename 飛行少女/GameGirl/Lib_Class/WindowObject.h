/*
*�E�B���h�E�֘A�N���X
*
*/
#ifndef WINDOW_OBJECT_H
#define WINDOW_OBJECT_H
#include <windows.h>
/*
*�E�B���h�E�쐬�N���X
*
*/
class WindowObject
{
private:

	//�E�B���h�E�N���X
	WNDCLASSEX m_wndc;
	//�E�B���h�E�n���h��
	HWND m_hWnd;
	//�E�B���h�E�̃^�C�g��
	char* m_wTitle;
	//�E�C���h�E�̕�
	int m_wWidth;
	//�E�B���h�E�̍���
	int m_wHeight;

public:
	
	//�R���X�g���N�^
	WindowObject(char* title,int width,int height);
	//�f�X�g���N�^
	~WindowObject();

	//�E�B���h�E�쐬
	HRESULT MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp));

	//�n���h���擾�p�֐�
	HWND GetHwnd();

};


#endif