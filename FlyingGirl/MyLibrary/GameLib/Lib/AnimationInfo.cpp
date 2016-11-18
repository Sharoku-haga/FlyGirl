/**
* @file AnimationInfo.cpp
* @brief AnimationInfoクラス実装
* @author haga
*/
#include "AnimationInfo.h"


AnimationInfo::AnimationInfo(int aniPat, int interval, float intervalTu, float intervalTv, bool isReverse)
	: m_animePattern(aniPat)
	, m_interval(interval)
	, m_currentInterval(0)
	, m_currentAnimeNum(0)
	, m_isReverseMode(isReverse)
	, m_hasReversed(false)
{
	m_animeInfo = new AnimeInfo[m_animePattern];

	for(int i = 0; i < m_animePattern; i++)
	{
		m_animeInfo[i].minTu = 0.0f + (intervalTu * i);
		m_animeInfo[i].minTv = 0.0f + (intervalTv * i);
		m_animeInfo[i].maxTu = intervalTu + ( intervalTu * i );
		m_animeInfo[i].maxTv = intervalTv + ( intervalTv * i );
	}
}


AnimationInfo::~AnimationInfo()
{
	Release();
}


/**アニメのコントロール関数*/
void AnimationInfo::ControlAnime()
{
	if(!m_isReverseMode)
	{
		ControlNormalMode();
	}
	else
	{
		ControlReverseMode();
	}
}

void AnimationInfo::ControlReverseMode()
{
	if(m_currentInterval != m_interval)
	{
		m_currentInterval++;
		return;
	}
	else
	{
		if(!m_hasReversed)
		{
			m_currentAnimeNum++;
		}
		else
		{
			m_currentAnimeNum--;
		}

		if(m_currentAnimeNum == 0)
		{
			m_hasReversed = false;
		}
		else if(m_currentAnimeNum == ( m_animePattern - 1 ))
		{
			m_hasReversed = true;
		}

		m_currentInterval = 0;
	}
}

void AnimationInfo::ControlNormalMode()
{
	if(m_currentInterval != m_interval)
	{
		m_currentInterval++;
		return;
	}
	else
	{
		if(m_currentAnimeNum == ( m_animePattern - 1 ))
		{
			m_currentAnimeNum = 0;
		}
		else
		{
			m_currentAnimeNum++;
		}
		m_currentInterval = 0;
	}
}

void AnimationInfo::SetAnimeInfo(int animeNum, float minTu, float maxTu, float minTv, float maxTv)
{
	m_animeInfo[( animeNum - 1 )].minTu = minTu;
	m_animeInfo[( animeNum - 1 )].maxTu = maxTu;
	m_animeInfo[( animeNum - 1 )].minTv = minTv;
	m_animeInfo[( animeNum - 1 )].maxTv = maxTv;
}

void AnimationInfo::Release()
{
	delete[] m_animeInfo;
}