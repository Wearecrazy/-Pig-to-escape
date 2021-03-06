//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"ObjBlock.h"

#include "GameHead.h"
#include "ObjHeroPigMan.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroPigMan::Init()
{
	m_px = 70.0f;		//位置
	m_py = 64.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;	//踏んでいるblockの種類を確認用

	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO_PIGMAN, 1);
}

//アクション
void CObjHeroPigMan::Action()
{
	//Xキー入力でジャンプ
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;
		}
	}
	//移動ベクトルの破棄
	m_vy = 0.0f;

	//Zキー入力で速度アップ
	if (Input::GetVKey('Z') == true)
	{
		//ダッシュ時の速度
		m_speed_power = 1.1f;
		m_ani_max_time = 2;
	}
	else
	{
		//通常速度
		m_speed_power = 0.5f;
		m_ani_max_time = 4;
	}
	//キーの入力方向
	if(Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if(Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;	//キー入力がない場合は静止フレームにする
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}
	
	//摩擦
	m_vx += -(m_vx*0.098);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_ENEMY_WOLF) != nullptr)
	{
		//主人公が敵とどの角度で当たっているかを確認
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY_WOLF);

		for (int i = 0; i < hit->GetCount(); i++)
		{


			//敵の左右に当たったら
			float r = hit_data[i]->r;
			if (r < 45 && r >= 0 || r>315)
			{
				m_vx = -5.0f;//左に移動させる
			}
			if (r > 135 && r < 225)
			{
				m_vx = +5.0f;//右に移動させる
			}

			if (r >= 225 && r < 315)
			{
				//敵の移動方向を主人公の位置に加算
				m_px += ((CObjEnemyWolf)hit_data[i]->o)->GetVx;

				CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//後方スクロールライン
				if (m_px < 80)
				{
					m_px = 80;
					b->SetScroll(b->GetScroll() + 5.0);
				}
				//前方スクロールライン
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0f);
				}
				//頭に乗せる処理
				if (m_vy < -1.0f)
				{
					//ジャンプしてる場合は下記の影響を出ないようにする
				}
				else
				{
					//主人公が敵の頭に乗っているので、Yvecは0にして落下させない
					//また、地面に当たっている判定にする
					m_vy = 0.0f;
					m_hit_down = true;
				}
			}
		}
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
	
	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjHeroPigMan::Draw()
{
	int AniData[4]=
	{
		1,0,2,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top	 = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top	 = 0.0f+m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}