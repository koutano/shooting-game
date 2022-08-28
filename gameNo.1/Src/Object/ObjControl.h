#pragma once
#include"ObjBase.h"
#include<vector>
#include"../Collision/FlexibleCollision.h"
//オブジェクトのインスタンスを持つクラス
//すべてのオブジェクトのアップデート、描画を行う
//オブジェクトはここで関数を作って生成する
class ObjControl
{
public:
	ObjControl() {};
	////シングルトン
	//static ObjControl* Instance()
	//{
	//	static ObjControl instance;
	//	return &instance;
	//}
	//デストラクタ
	~ObjControl() 
	{ 
		for (auto& obj : objects)
		{
			delete obj;
		}
	};
	//更新用
	void Update();
	//描画用
	void Draw();
	//当たり判定更新用
	void CollisionUpdate();

	//オブジェクト生成用関数
	//BackGround生成
	void CreateBackGround();
	/*
	Player生成
	引数
	1:posX(float)
	2:posY(float)
	*/
	void CreatePlayer(float posX_, float posY_);
	/*
	Bullet生成
	引数
	1:posX(float)
	2:posY(float)
	*/
	void CreateBullet(float posX_,float posY_);
	/*
	Enemy生成
	引数
	1:posX(float)
	2:posY(float)　　　
	*/
	void CreateEnemy(float posX_, float posY_);
private:
	//オブジェクト格納用　
	std::vector<ObjBase*> objects;
	//当たり判定
	FlexibleCollision collision;
	//Player player;
};
