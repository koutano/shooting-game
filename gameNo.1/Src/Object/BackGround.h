#pragma once
#include"ObjBase.h"
//背景クラス
class BackGround :public ObjBase
{
public:
	/*
	コンストラクタ
	*/
	BackGround() :
		ObjBase(0, 0, "BackGround")
	{

	}
	//デストラクタ
	~BackGround()override { delete colType; }
	//更新用
	void Update()override;
	//描画用
	void Draw()override;
	//当たり時動作
	//背景なので何もしない
	void OnCollision(ObjBase* obj_)override;

private:

};