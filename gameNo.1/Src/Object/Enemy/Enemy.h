#pragma once
#include"EnemyBase.h"
class Enemy :public EnemyBase
{
public:
	Enemy(float posX_,float posY_,float speed_):
		EnemyBase(posX_,posY_,200,200,"Enemy"),
		speed(speed_)
	{

	}
	~Enemy()override { delete colType; }
	void Update()override;
	void Draw()override;
	void OnCollision(ObjBase* obj_)override;

private:
	float speed;
};
