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
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^
	Draw::LoadImage(L"BossBack.png", 1, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	//CObjHero* obj = new CObjHero();
	//Objs::InsertObj(obj, OBJ_HERO, 10);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);

	//�^�C��������
	//m_time = 0;

	//Test�p�@�G�I�u�W�F�N�g�쐬
	CObjEnemy* obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Test�p�@�G�I�u�W�F�N�g�쐬
	obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMYWOLF, 10);


}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}