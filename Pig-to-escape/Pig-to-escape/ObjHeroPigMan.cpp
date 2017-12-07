//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjHeroPigMan.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroPigMan::Init()
{
	
}

//アクション
void CObjHeroPigMan::Action()
{
	
}

//ドロー
void CObjHeroPigMan::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 0.0f;
	src.m_bottom = 0.0f;

	//表示位置の設定
	dst.m_top	 = 0.0f;
	dst.m_left	 = 0.0f;
	dst.m_right	 = 0.0f;
	dst.m_bottom = 0.0f;
}