/**
* @file MyLibrary.h
* @brief MyLibrary�̃w�b�_�[�t�@�C�����܂Ƃ߂��w�b�_<br>
* �����܂ł��̃w�b�_�[�͊m�F�p�Ȃ̂ŁAinclude�͂��Ȃ�����
* @author haga
*/

#define MY_LIBRARY_H

#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//------------------------------------------------------------------------------
//					MyLibrary���̎�ȃw�b�_�[�t�@�C��
//------------------------------------------------------------------------------

#include "GameLib/GameLib.h"				//!< Facade�p�^�[���̃��C�u����
#include "Font/Font.h"					//!< �t�H���g�N���X
#include "Camera/Camera.h"				//!< �J�����N���X
#include "Light/Light.h"					//!< ���C�g�N���X

/*
�ݒ肷��Lib
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib,"dxguid.lib")
#pragma comment (lib,"shlwapi.lib")
#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"Dsound.lib")
#pragma comment (lib,"MyLibrary.lib")
*/

//----------------------------------------------------------------------------------------
//				�ȉ���GameLib��Lib�t�@���_���̃w�b�_�[�t�@�C��
//----------------------------------------------------------------------------------------
#include "GameLib/Lib/WindowCreator.h"				//!< Window�֘A�N���X
#include "GameLib/Lib/GraphicsDevice.h"				//!< GraphicsDevice�̃N���X
#include "GameLib/Lib/InputDevice.h"				//!< DirectInput�f�o�C�X�֘A�N���X
#include "GameLib/Lib/InputKey.h"					//!< �L�[�{�[�h����֘A�N���X
#include "GameLib/Lib/InputMouse.h"					//!< �}�E�X����֘A�N���X
#include "GameLib/Lib/TextureManager.h"				//!< �e�N�X�`���[�Ǘ��N���X
#include "GameLib/Lib/XFileManager.h"				//!< X�t�@�C���Ǘ��N���X
#include "GameLib/Lib/XFile.h"						//!< X�t�@�C���N���X
#include "GameLib/Lib/SoundFileManager.h"			//!< �T�E���h�Ǘ��N���X
#include "GameLib/Lib/VertexManager.h"				//!< ���_�Ǘ��N���X
#include "GameLib/Lib/Vertex.h"						//!< ���_�N���X
#include "GameLib/Lib/DebugFont.h"					//!< �f�o�b�N�t�H���g�N���X
#include "GameLib/Lib/DebugTimer.h"					//!< �f�o�b�N�^�C�}�[�N���X

#endif // MY_LIBRARY_H