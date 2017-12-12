//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemyFarmer.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjEnemyFarmer::CObjEnemyFarmer(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemyFarmer::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当り判定を作成
	//Hits::SetHitBox(this,m_x,m_y,)
}

//アクション
void CObjEnemyFarmer::Action()
{
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

	//ベクトルの長さを求める
	float root = 0.0f;
	root = m_vx * m_vx + m_vy * m_vy;
	root = sqrt(root);//ルートを求める

	//長さが0かどうか調べる
	if (root == 0.0f)
	{
		;
	}
	else
	{
		//正規化を行う
		m_vx = 1.0f / root * m_vx;
		m_vy = 1.0f / root * m_vy;
	}

	//速度
	m_vx *= 1.0f;
	m_vy *= 1.0f;

	//移動ベクトルを座標に加算
	m_x += m_vx;
	m_y += m_vy;

	//HitBox内容の更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//農家と接触しているか
	if (hit->CheckObjNameHit(OBJ_HEROPIGMAN) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjEnemyFarmer::Draw()
{
	/*後、設定-----------------------------------
	
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //切り取り位置
	RECT_F dst; //表示位置

	//切り取り位置設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 0.0f;
	src.m_bottom = 0.0f;

	//表示位置設定
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 0.0f;
	dst.m_bottom = 0.0f;

	//グラフィックを描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
	---------------------------------------------*/
}