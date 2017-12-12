//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHeroPigMan.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHeroPigMan::Init()
{
	m_px = 70.0f;		//�ʒu
	m_py = 64.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;	//����ł���block�̎�ނ��m�F�p

	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHeroPigMan::Action()
{
	//X�L�[���͂ŃW�����v
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;
		}
	}
	//�ړ��x�N�g���̔j��
	m_vy = 0.0f;

	//Z�L�[���͂ő��x�A�b�v
	if (Input::GetVKey('Z') == true)
	{
		//�_�b�V�����̑��x
		m_speed_power = 1.1f;
		m_ani_max_time = 2;
	}
	else
	{
		//�ʏ푬�x
		m_speed_power = 0.5f;
		m_ani_max_time = 4;
	}
	//�L�[�̓��͕���
	if(Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if(Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}
	
	//���C
	m_vx += -(m_vx*0.098);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_ENEMYWOLF) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_ENEMYWOLF);

		for (int i = 0; i < hit->GetCount(); i++)
		{


			//�G�̍��E�ɓ���������
			float r = hit_data[i]->r;
			if (r < 45 && r >= 0 || r>315)
			{
				m_vx = -5.0f;//���Ɉړ�������
			}
			if (r > 135 && r < 225)
			{
				m_vx = +5.0f;//�E�Ɉړ�������
			}

			if (r >= 225 && r < 315)
			{
				//�G�̈ړ���������l���̈ʒu�ɉ��Z
				m_px += ((CObjEnemyWolf)hit_data[i]->o)->GetVx;

				CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//����X�N���[�����C��
				if (m_px < 80)
				{
					m_px = 80;
					b->SetScroll(b->GetScroll() + 5.0);
				}
				//�O���X�N���[�����C��
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0f);
				}
				//���ɏ悹�鏈��
				if (m_vy < -1.0f)
				{
					//�W�����v���Ă�ꍇ�͉��L�̉e�����o�Ȃ��悤�ɂ���
				}
				else
				{
					//��l�����G�̓��ɏ���Ă���̂ŁAYvec��0�ɂ��ė��������Ȃ�
					//�܂��A�n�ʂɓ������Ă��锻��ɂ���
					m_vy = 0.0f;
					m_hit_down = true;
				}
			}
		}
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
	
	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}

//�h���[
void CObjHeroPigMan::Draw()
{
	int AniData[4]=
	{
		1,0,2,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	 = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f+m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}