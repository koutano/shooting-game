#pragma once
#include"../RectObjBase.h"
class Bullet :public RectObjBase
{
public:
	Bullet(float posX_,float posY_):
		RectObjBase(posX_,posY_,100,50,"Bullet")
	{
	}
	~Bullet()override { delete col; }
	void Update()override;
	void Draw()override;
	void OnCollision(ObjBase* obj_)override;
private:


};