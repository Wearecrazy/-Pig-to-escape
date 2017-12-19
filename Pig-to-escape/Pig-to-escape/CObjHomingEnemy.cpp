//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "CObjHomingEnemy.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}
//ｲﾆｼｬﾗｲｽﾞ
void CObjHomingEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 1);
}
//ドロー
void CObjHomingEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f+m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f+m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//アクション
void CObjHomingEnemy::Action()
{
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;
	
		//ベクトルの長さを求める
		float r = 0.0f;
		r = m_vx*m_vx + m_vy*m_vy;
		r = sqrt(r);//ｒをルートを求める

		//長さが0かどうか調べる
		if (r == 0.0f)
		{
			;//0なら何もしない
		}
		else
		{
			//正規化を行う
			m_vx = 1.0f / r*m_vx;
			m_vy = 1.0f / r*m_vy;
		}
	//速度をつける
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//ついてくるおっさんが領域外に出たらおっさんを破棄する(ここいらんかも)
	if (m_x < -32.0f)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//ついてくるおっさんが所有するHitBoxに削除する
	}

	//弾丸と接触とかあるけど省く(指南書8の5)


}