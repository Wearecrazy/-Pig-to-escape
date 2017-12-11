//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		m_key_flag = false;
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"YOU LOST", 0, 0, 32, c);
	Font::StrDraw(L"NEXT_CHALLENGE:PushEnterKey", 0, 80, 32, c);




}