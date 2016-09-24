/**
*@file Scene.h
*@brief �V�[���N���X�̃w�b�_�t�@�C��
*@author�@�F��M�V
*
*/
#ifndef SCENE_H
#define SCENE_H

#include"CommonItems.h"
#include"Score.h"

/**
*�V�[���N���X
*/
class Scene
{
private:

public:
	/**�R���X�g���N�^*/
	Scene(){};

	/**�f�X�g���N�^*/
	virtual ~Scene(){};

	/**�R���g���[���֐�*/
	virtual SceneID Control() = 0;
	/**�`��֐�*/
	virtual void Draw() = 0;

};


#endif	// SCENE_H