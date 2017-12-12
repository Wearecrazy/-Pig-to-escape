//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemyFarmer.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemyFarmer::CObjEnemyFarmer(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjEnemyFarmer::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//���蔻����쐬
	//Hits::SetHitBox(this,m_x,m_y,)
}

//�A�N�V����
void CObjEnemyFarmer::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�x�N�g���̒��������߂�
	float root = 0.0f;
	root = m_vx * m_vx + m_vy * m_vy;
	root = sqrt(root);//���[�g�����߂�

	//������0���ǂ������ׂ�
	if (root == 0.0f)
	{
		;
	}
	else
	{
		//���K�����s��
		m_vx = 1.0f / root * m_vx;
		m_vy = 1.0f / root * m_vy;
	}

	//���x
	m_vx *= 1.0f;
	m_vy *= 1.0f;

	//�ړ��x�N�g�������W�ɉ��Z
	m_x += m_vx;
	m_y += m_vy;

	//HitBox���e�̍X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�_�ƂƐڐG���Ă��邩
	if (hit->CheckObjNameHit(OBJ_HEROPIGMAN) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjEnemyFarmer::Draw()
{
	/*��A�ݒ�-----------------------------------
	
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�؂���ʒu
	RECT_F dst; //�\���ʒu

	//�؂���ʒu�ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 0.0f;
	src.m_bottom = 0.0f;

	//�\���ʒu�ݒ�
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 0.0f;
	dst.m_bottom = 0.0f;

	//�O���t�B�b�N��`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
	---------------------------------------------*/
}