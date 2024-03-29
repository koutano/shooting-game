#pragma once
#include"Collider.h"
//矩形状クラス
class RectCollider :public Collider
{
public:
	RectCollider(float x_, float y_, float width_, float height_) :
		Collider(x_, y_),
		width(width_),
		height(height_)
	{
	}

	virtual ~RectCollider() {}

	ColliderType GetType()const { return Collider_Rect; }

	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetWidth()const { return width; }
	float GetHeight()const { return height; }

private:
	float width;
	float height;
};