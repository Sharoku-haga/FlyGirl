/**
*@file SceneManager.cpp
*@brief �V�[���}�l�[�W���[�N���X��cpp�t�@�C��
*@author�@�F��M�V
*
*/
#include"LibClass.h"
#include"CommonItems.h"
#include"Scene.h"
#include"SceneManager.h"
#include"SceneFactory.h"


// �R���X�g���N�^
SceneManager::SceneManager()
{
	m_pScene = nullptr;
	m_GraphicDevice = &GraphicsD3D::GetInstance();

	m_currentSceneID = Logo_scene;
#ifdef DEBUG

	m_nextSceneID = Game_scene;

#else

	m_nextSceneID = Logo_scene;
#endif

	m_state = Scene_Create;
	m_gameEnd = false;
}

// �f�X�g���N�^
SceneManager:: ~SceneManager()
{
	if (m_pScene != nullptr)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}
}

// �Q�[����S�̂̓�����`��𑍊�����֐�
bool SceneManager::RunGame()
{

	Control();

	m_GraphicDevice->StartRender(D3DFVF_CUSTOMVERTEX);

	Render();

	m_GraphicDevice->EndRender();

	return m_gameEnd;
}

// �V�[���}�l�[�W���[�̃R���g���[���֐�
void SceneManager::Control()
{
	if (m_pScene == nullptr)
	{
		m_currentSceneID = m_nextSceneID;
		if (m_currentSceneID == End_scene)
		{
			m_gameEnd = true;

			return;
		}
	}

	// �V�[���̏�Ԃ��m�F���A�������s��
	switch (m_state)
	{
	case Scene_Create:
		// �V�[��ID�����ƂɃV�[���𐶐�����
		m_pScene = SceneFactory::Instance().CreateScene(m_currentSceneID);

		m_state = Scene_Run;
		break;

	case Scene_Run:
		// �V�[��ID���`�F�b�N���Č��݂̃V�[��ID�ƈႤ�Ȃ猻�݂̃V-�����I��点��
		if ((m_nextSceneID = m_pScene->Control()) != m_currentSceneID)
		{
			m_state = Scene_End;
		}

		break;

	case Scene_End:

		delete m_pScene;
		m_pScene = nullptr;

		// ���̃V�[�����쐬�ł����Ԃɂ���
		m_state = Scene_Create;

		break;
	}

	return;
}

// �V�[���}�l�[�W���[�̕`��֐�
void SceneManager::Render()
{
	if (m_state == Scene_Run)
	{
		m_pScene->Draw();
		
		return;
	}
	else
	{
		return;
	}
}

