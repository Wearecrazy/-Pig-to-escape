//STLデバッグ機能をOffにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512*512ピクセル)
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録
	Draw::LoadImage(L"BossBack.png", 1, TEX_SIZE_512);

	//主人公オブジェクト作成
	//CObjHero* obj = new CObjHero();
	//Objs::InsertObj(obj, OBJ_HERO, 10);

	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);

	//タイム初期化
	//m_time = 0;

	//Test用　敵オブジェクト作成
	CObjEnemy* obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMY, 10);

	//Test用　敵オブジェクト作成
	obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMYWOLF, 10);


}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}