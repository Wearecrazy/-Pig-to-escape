//STL�f�o�b�O�@�\��Off�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include"ObjBackground.h"
#include"ObjBlock.h"
#include "ObjEnemyHawk.h"
#include "ObjEnemyWolf.h"
#include "ObjGameOver.h"
#include"ObjHeroPigMan.h"
#include "ObjStage.h"
#include "ObjTitle.h"


//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512*512�s�N�Z��)
	Draw::LoadImage(L"image1.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);



	//��l���I�u�W�F�N�g�쐬
	CObjHeroPigMan* obj = new CObjHeroPigMan();
	Objs::InsertObj(obj, OBJ_HERO_PIGMAN, 10);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);

	//�X�e�[�W
/*	CObjStage* obj = new CObjStage();
	Objs::InsertObj(obj, OBJ_STAGE, 5);*/


	//�^�C��������
	//m_time = 0;

	//Test�p�@�G�I�u�W�F�N�g�쐬
	CObjEnemyWolf* obje = new CObjEnemyWolf();
	Objs::InsertObj(obje, OBJ_ENEMY_WOLF, 10);

	//Test�p�@�G�I�u�W�F�N�g�쐬
	obje = new CObjEnemyWolf();
	Objs::InsertObj(obje, OBJ_ENEMY_WOLF, 10);


}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}