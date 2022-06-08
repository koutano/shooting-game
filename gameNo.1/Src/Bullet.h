#pragma once
#include"ObjBase.h"

class Bullet :public ObjBase
{
public:
	Bullet(Vector2 pos_):
		ObjBase(pos_,"Bullet")
	{
	}

	void Update()override;
	void Draw()override;

private:


};