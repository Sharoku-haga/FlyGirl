/**
*@file Texture.h
*
*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <d3dx9.h>
#include <d3d9.h>
#include"GraphicsD3D.h"

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};


/**
*テクスチャーを管理するクラス
*
*/
class Texture
{
private:
	//テクスチャーを格納
	LPDIRECT3DTEXTURE9	m_pTexture;
	//デバイス格納用
	IDirect3DDevice9*	m_pD3Device;

public:
	
	//コンストラクタ
	Texture();
	//デストラクタ
	~Texture();

	//画像読み込み
	HRESULT LoadTex(char* text);

	//画像読み込みEx
	HRESULT LoadTexEx(char* text,int a,int r,int g,int b,bool size);

	//画像描画
	void RenderTex(CUSTOMVERTEX* setdraw);

	//デバイスを取得する関数(static用)
	void GetDevice();

	//テクスチャーを格納しているかを確認
	LPDIRECT3DTEXTURE9 GetStateTex(){ return m_pTexture; }

};


#endif