#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEnemyFarmer : public CObj
{
public:
	CObjEnemyFarmer(float x, float y);//コンストラクタ
	~CObjEnemyFarmer() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;		//農家のX位置
	float m_y;		//農家のY位置
	float m_vx;		//農家の移動ベクトルX
	float m_vy;		//農家の移動ベクトルY

	int m_ani_time;	//アニメーションフレーム動作間隔
	int m_ani_frame;//作画フレーム
	float m_ani_max_time;//アニメーション動作間隔最大値
	float m_speed_powr; //スピードパワー

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//移動向き制御用
	bool m_move;
};