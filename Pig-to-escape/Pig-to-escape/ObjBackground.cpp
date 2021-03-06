#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//ｲﾆｼｬﾗｲｽﾞ
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;

}

//アクション
void CObjBackground::Action()
{
	//背景１の動作
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;

	//背景２の動作
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;




}
//ドロ
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

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	//背景２位置の設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);






}//１１の１０から