//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjHeroPigMan.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHeroPigMan::Init()
{
	
}

//�A�N�V����
void CObjHeroPigMan::Action()
{
	
}

//�h���[
void CObjHeroPigMan::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 0.0f;
	src.m_bottom = 0.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f;
	dst.m_left	 = 0.0f;
	dst.m_right	 = 0.0f;
	dst.m_bottom = 0.0f;
}