#pragma once
#include"ObjBase.h"

class Enemy :public ObjBase
{
public:
	Enemy(Vector2 pos_):
		ObjBase(pos_,"Enemy")
	{

	}

	void Update()override;
	void Draw()override;

private:
	float speed;
};
