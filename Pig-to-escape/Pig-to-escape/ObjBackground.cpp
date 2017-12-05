#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//ｲﾆｼｬﾗｲｽﾞ
void CObjBackground::Init()
{

}

//アクション
void CObjBackground::Action()
{

}
//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);


}//１１の１０から