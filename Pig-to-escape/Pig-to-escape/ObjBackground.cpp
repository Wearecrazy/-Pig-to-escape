#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Ƽ�ײ��
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;

}

//�A�N�V����
void CObjBackground::Action()
{
	//�w�i�P�̓���
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;

	//�w�i�Q�̓���
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;




}
//�h��
void CObjBackground::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�w�i�Q�ʒu�̐ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);






}//�P�P�̂P�O����