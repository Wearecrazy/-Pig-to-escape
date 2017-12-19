#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ついてくるおっさん
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);//コンストラクタ
	~CObjHomingEnemy() {};
	void Init();//ｲﾆｼｬﾗｲｽﾞ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//ついてくるおっさんのX方向位置
	float m_y;//ついてくるおっさんのY方向位置
	float m_vx;//ついてくるおっさんの移動ベクトルX
	float m_vy;//ついてくるおっさんの移動ベクトルY




};