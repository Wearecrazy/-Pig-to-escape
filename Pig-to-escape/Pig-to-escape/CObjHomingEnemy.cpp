//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "CObjHomingEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�Ƽ�ײ��
void CObjHomingEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 1);
}
//�h���[
void CObjHomingEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f+m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//�A�N�V����
void CObjHomingEnemy::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;
	
		//�x�N�g���̒��������߂�
		float r = 0.0f;
		r = m_vx*m_vx + m_vy*m_vy;
		r = sqrt(r);//�������[�g�����߂�

		//������0���ǂ������ׂ�
		if (r == 0.0f)
		{
			;//0�Ȃ牽�����Ȃ�
		}
		else
		{
			//���K�����s��
			m_vx = 1.0f / r*m_vx;
			m_vy = 1.0f / r*m_vy;
		}
	//���x������
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//���Ă��邨�����񂪗̈�O�ɏo���炨�������j������(��������񂩂�)
	if (m_x < -32.0f)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���Ă��邨�����񂪏��L����HitBox�ɍ폜����
	}

	//�e�ۂƐڐG�Ƃ����邯�ǏȂ�(�w�쏑8��5)


}