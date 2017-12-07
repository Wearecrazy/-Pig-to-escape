#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公,豚男
class CObjHeroPigMan : public CObj
{
	public:
		CObjHeroPigMan() {};
		~CObjHeroPigMan() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		
}; 
