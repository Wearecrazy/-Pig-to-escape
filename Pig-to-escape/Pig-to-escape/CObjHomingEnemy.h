#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���Ă��邨������
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);//�R���X�g���N�^
	~CObjHomingEnemy() {};
	void Init();//�Ƽ�ײ��
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//���Ă��邨�������X�����ʒu
	float m_y;//���Ă��邨�������Y�����ʒu
	float m_vx;//���Ă��邨������̈ړ��x�N�g��X
	float m_vy;//���Ă��邨������̈ړ��x�N�g��Y




};