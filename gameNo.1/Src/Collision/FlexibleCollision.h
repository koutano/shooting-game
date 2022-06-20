#pragma once
#include"Collision.h"
#include"Collider.h"
#include"CircleCollider.h"
#include"RectCollider.h"
/*
	任意の形状の当たり判定を行うクラス
*/
class FlexibleCollision :public Collision
{
public:
	FlexibleCollision()
	{
		colTable[Collider_Circle]	[Collider_Circle]	= new CircleAndCircle();
		colTable[Collider_Circle]	[Collider_Rect]		= new CircleAndRect();
		colTable[Collider_Rect]		[Collider_Circle]	= new RectAndCircle();
		colTable[Collider_Rect]		[Collider_Rect]		= new RectAndRect();
	}

	virtual ~FlexibleCollision() {
		for (int i = 0; i < ColliderTypeNum; ++i) {
			for (int j = 0; j < ColliderTypeNum; ++j) {
				delete colTable[i][j];
			}
		}
	}

	bool Judge(const Collider& c1, const Collider& c2) {
		if (&c1 == nullptr || &c2 == nullptr)
		{
			return false;
		}
		return colTable[c1.GetType()][c2.GetType()]->Judge(c1, c2);
	}

private:
	Collision* colTable[ColliderTypeNum][ColliderTypeNum];
};

