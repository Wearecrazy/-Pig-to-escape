//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"
#include"ObjBlock.h"
#include"GameHead.h"
#include"ObjEnemyWolf.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemyWolf::Init()
{
	m_px = 100.0f;		//�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_powr = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;	//�A�j���[�V�����Ԋu��

	m_move = false;	//true=�E   false=��


	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}

//�A�N�V����
void CObjEnemyWolf::Action()
{
	//����
	if (m_py > 1000.0f)
	{
		;
	}

	//�ʏ푬�x
	m_speed_powr = 0.5f;
	m_ani_time = 4;

	//�u���b�N�Փ˂Ō����ύX
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{
		m_move = false;
	}

	//����
	if (m_move==false)
	{
		m_vx += m_speed_powr;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if(m_move==true)
	{
		m_vx -= m_speed_powr;
		m_posture = 0.0f;
		m_ani_time = 1;
	}
	

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame = -4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);


	/*------------------------------------------------------------------------------
	//�u���b�N���m�p�̕ϐ����������߃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJBLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, m_vx, m_vy,
		&d
	);-------------------------------------------------------------------------------
	*/



	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void CObjEnemyWolf::Draw()
{
	int AniData[4]=
	{
		1,0,2,0,
	};



/*	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f;
	src.m_left = 0.0f +AniData[m_ani_frame] * 64;
	src.m_right = 0.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;


	//�u���b�N���������Ă���
	CObjBlock* block=(CObjBlock*) Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px+block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_pxblock->GetScroll();
	dst.m_bottom = 64.0 + m_py;

	//�`��
	Draw::Draw(0, &src, c, 0.0f);*/

}

//P�EP10-19����