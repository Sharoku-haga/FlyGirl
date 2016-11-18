/**
* @file		AnimationInfoManager.h
* @brief	AnimationInfoManagerクラスヘッダ
* @author	haga
*/
#ifndef ANIMATION_INFO_MANAGER_H
#define ANIMATION_INFO_MANAGER_H

#include <map>

class AnimationInfo;
/**
* AnimationInfoクラスを管理するクラス
*/
class AnimationInfoManager
{
public:
	AnimationInfoManager();
	~AnimationInfoManager();


	/**
	* アニメーション情報を解放する関数
	* @param[in] key	mapのキー
	*/
	void Release(int key);

	/**全てのアニメーション情報を解放する関数*/
	void ReleaseALL();

private:
	std::map<int, AnimationInfo> m_animationInfo;			//!< アニメーション情報を格納する変数
};

#endif	// ANIMATION_INFO_MANAGER_H