#pragma once
#include"../RectObjBase.h"

class Enemy :public RectObjBase
{
public:
	Enemy(float posX_,float posY_,float speed_):
		RectObjBase(posX_,posY_,200,200,"Enemy",Group_Enemy),
		speed(speed_)
	{

	}
	~Enemy()override { delete col; }
	void Update()override;
	void Draw()override;
	void OnCollision(ObjBase* obj_)override;

private:
	float speed;
};
