#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�u���b�N���w�i
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[150][20]);
	~CObjBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:


};
