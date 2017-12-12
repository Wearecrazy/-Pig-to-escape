#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock(int mapdata[30][20]);
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	int m_map[30][20];

	float m_scroll;

};
