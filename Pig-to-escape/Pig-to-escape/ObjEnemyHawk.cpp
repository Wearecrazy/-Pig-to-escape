//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"


#include"GameHead.h"
#include"ObjEnemyHawk.h"

//使用するネームスペース
using namespace GameL;

CObjEnemyHawk::CObjEnemyHawk(float x, float y)
{
	m_px = x;//位置
	m_py = y;
}
//イニシャライズ
void CObjEnemyHawk::Init()
{
	m_px = 100.0f;		//位置
	m_py = 0.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;


	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_powr = 0.5f;//通常速度
	m_ani_max_time = 4;	//アニメーション間隔幅

	m_move = false;	//true=右   false=左


					//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY_HAWK, 1);
}

//アクション
void CObjEnemyHawk::Action()
{
	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_powr = 0.5f;
	m_ani_time = 4;



	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);







	//位置の更新
	m_px += m_vx;
	m_py += m_vy;


	/*
	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);*/
}

//ドロー
void CObjEnemyHawk::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	// 描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 64.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 0.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;




	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0;
	dst.m_right = 0.0;
	dst.m_bottom = 64.0;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}