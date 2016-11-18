/**
* @file		AnimationInfoManager.cpp
* @brief	AnimationInfoManagerクラス実装
* @author	haga
*/
#include "AnimationInfo.h"
#include "AnimationInfoManager.h"


AnimationInfoManager::AnimationInfoManager()
{
}


AnimationInfoManager::~AnimationInfoManager()
{
	ReleaseALL();
}

void AnimationInfoManager::RegisterAnimationInfo(int key, int aniPat, 
	int interval, float intevalTu, float intevalTv, bool isReverse)
{
	m_animationInfo[key] = new AnimationInfo(aniPat, interval, intevalTu, intevalTv, isReverse);
}

void AnimationInfoManager :: SetAnimeInfo(int key, int animeNum, float minTu, float maxTu, float minTv, float maxTv)
{
	m_animationInfo[key]->SetAnimeInfo(animeNum, minTu, maxTu, minTv, maxTv);
}

void AnimationInfoManager::ControlAnime(int key)
{
	m_animationInfo[key]->ControlAnime();
}

// アニメーション情報を解放する関数
void AnimationInfoManager::Release(int key)
{
	m_animationInfo[key]->Release();
	m_animationInfo.erase(key);
}

// 全てのアニメーション情報を解放する関数
void AnimationInfoManager::ReleaseALL()
{
	m_animationInfo.clear();
}