#pragma once
#include"../RectObjBase.h"
#include<vector>
#include"../../Collision/Collider.h"
//プレイヤークラス
class Player :public RectObjBase
{
public:
	/*
	コンストラクタ
	引数
	1:初期座標X(float)
	2:初期座標Y(float)
	*/
	Player(float posX_,float posY_) :
		RectObjBase(posX_,posY_, 200, 200, "Player",ObjGroup::Group_Player)
	{

	}
	//デストラクタ
	~Player() override { delete colType; }
	
	//更新用
	void Update()override;
	//描画用
	void Draw()override;
	//当たり時動作
	void OnCollision(ObjBase* obj_)override;

private:

};