#pragma once
#include"EnemyBase.h"
//敵クラス
class Enemy :public EnemyBase
{
public:
	/*
	コンストラクタ
	引数
	1:初期座標X(float)
	2:初期座標Y(float)
	3:速度(float)
	*/
	Enemy(float posX_,float posY_,float speed_):
		EnemyBase(posX_,posY_,200,200,"Enemy"),
		speed(speed_)
	{

	}
	//デストラクタ
	~Enemy()override { delete colType; }
	//更新用
	void Update()override;
	//描画用
	void Draw()override;
	//当たり時動作
	void OnCollision(ObjBase* obj_)override;

private:
	float speed;
};
