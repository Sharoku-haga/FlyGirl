/**
*@file SceneManager.h
*@brief �V�[���}�l�[�W���[�N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"

/**�f�o�b�N�p�}�N��<br>*/
//#define DEBUG

/**
*�V�[�����Ǘ�����N���X
*
*/

class SceneManager
{
	/**�V�[���̏��*/
	enum SceneState
	{
		Scene_Create,			//!<����
		Scene_Run,				//!<���s
		Scene_End				//!<�I��
	};

private:
	/**�V�[���N���X*/
	Scene* m_pScene;

	/**�O���t�B�b�N�f�o�C�X*/
	GraphicsD3D* m_GraphicDevice;

	/**���݂̃V�[��ID���i�[����ϐ�*/
	SceneID m_currentSceneID;

	/**���̃V�[��ID���i�[����ϐ�*/
	SceneID m_nextSceneID;

	/**�V�[���̏�Ԋm�F�ϐ�*/
	SceneState m_state;

	/**�Q�[���G���h�t���O*/
	bool m_gameEnd;

public:

	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();

	//�Q�[����S�̂̓����𑍊�����֐�
	bool RunGame();
	//�R���g���[���֐�
	void Control();
	//�`��֐�
	void Render();

};


#endif	// SCENE_MANAGER_H