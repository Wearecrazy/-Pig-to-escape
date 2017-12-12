#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G
class CObjEnemyFarmer : public CObj
{
public:
	CObjEnemyFarmer(float x, float y);//�R���X�g���N�^
	~CObjEnemyFarmer() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;		//�_�Ƃ�X�ʒu
	float m_y;		//�_�Ƃ�Y�ʒu
	float m_vx;		//�_�Ƃ̈ړ��x�N�g��X
	float m_vy;		//�_�Ƃ̈ړ��x�N�g��Y

	int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//���t���[��
	float m_ani_max_time;//�A�j���[�V��������Ԋu�ő�l
	float m_speed_powr; //�X�s�[�h�p���[

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ���������p
	bool m_move;
};