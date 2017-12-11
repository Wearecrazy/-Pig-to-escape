#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//g—p‚·‚éƒl[ƒ€ƒXƒy[ƒX
using namespace GameL;

//²Æ¼¬×²½Ş
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;

}

//ƒAƒNƒVƒ‡ƒ“
void CObjBackground::Action()
{
	//”wŒi‚P‚Ì“®ì
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;

	//”wŒi‚Q‚Ì“®ì
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;




}
//ƒhƒ
void CObjBackground::Draw()
{
	//•`‰æƒJƒ‰[î•ñ@R=RED G=Green B=Blue A=alpha(“§‰ßî•ñ)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //•`‰æØ‚èæ‚èˆÊ’u
	RECT_F dst; //•`‰ææ•\¦ˆÊ’u

	//Ø‚èæ‚èˆÊ’u‚Ìİ’è
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//”wŒi1‚ÌˆÊ’u‚ğİ’è‚µ•`‰æ
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	//”wŒi‚QˆÊ’u‚Ìİ’è‚µ•`‰æ
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);






}//‚P‚P‚Ì‚P‚O‚©‚ç