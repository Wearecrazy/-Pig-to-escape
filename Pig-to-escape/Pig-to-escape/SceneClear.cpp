//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"
#include"ObjClear.h"
//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������\�b�h
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"��");
	Font::SetStrTex(L"��");

	//�N���A�I�u�W�F�N�g�쐬
	CObjClear*obj = new CObjClear();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//�N���A�I�u�W�F�N�g�o�^
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}