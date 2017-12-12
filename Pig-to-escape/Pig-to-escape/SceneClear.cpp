//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"
#include"ObjClear.h"
//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"卍");
	Font::SetStrTex(L"卍");

	//クリアオブジェクト作成
	CObjClear*obj = new CObjClear();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//クリアオブジェクト登録
}

//実行中メソッド
void CSceneClear::Scene()
{

}