#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	OBJ_BACKGROUND,//背景
	OBJ_ENEMY_WOLF,//敵 狼
	OBJ_ENEMY_HAWK,//敵　鳥
	OBJ_TITLE,//タイトル
	OBJ_GAME_OVER,//ゲームオーバー
	OBJ_HERO_PIGMAN,//主人公
	OBJ_BLOCK,//ブロック
	OBJ_STAGE,
	OBJ_CLEAR,
	OBJ_HOMING_ENEMY,
					//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjHeroPigMan.h"
#include "ObjBackground.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include"ObjClear.h"
#include"ObjBlock.h"
#include"ObjEnemyWolf.h"
#include"ObjEnemyHawk.h"
#include"ObjStage.h"
#include "CObjHomingEnemy.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle