#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Ƽ�ײ��
void CObjBackground::Init()
{

}

//�A�N�V����
void CObjBackground::Action()
{

}
//�h���[
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

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);


}//�P�P�̂P�O����