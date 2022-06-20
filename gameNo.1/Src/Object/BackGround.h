#pragma once
#include"ObjBase.h"

class BackGround :public ObjBase
{
public:
	BackGround(float posX_,float posY_):
		ObjBase(posX_,posY_,"BackGround")
	{

	}
	~BackGround()override { delete col; }
	void Update()override;
	void Draw()override;
	void OnCollision(ObjBase* obj_)override;

private:

};