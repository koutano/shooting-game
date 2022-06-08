#pragma once
#include"ObjBase.h"

class BackGround :public ObjBase
{
public:
	BackGround(Vector2 pos_):
		ObjBase(pos_,"BackGround")
	{

	}

	void Update()override;
	void Draw()override;

private:

};