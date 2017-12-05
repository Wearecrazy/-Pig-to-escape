#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームメイン
class CObjStage  :public CObj
{
public:
	CObjStage() {};
	~CObjStage() {};
	void Init();
	void Action();
	void Draw();
private:
	

};