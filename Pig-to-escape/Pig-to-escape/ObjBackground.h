#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�w�i
class CObjBackground : public CObj
{
public :
	CObjBackground() {};
	~CObjBackground() {};
	void Init();//�Ƽ�ײ��
	void Action();//�A�N�V����
	void Draw();//�h���[
private:

	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i�Q�̈ʒu���

};//�^�C�g���쐬12����