#pragma once
#include"Collider.h"
//‰~Œ`óƒNƒ‰ƒX
class CircleCollider :public Collider
{
public:
	CircleCollider(float x_, float y_, float radius_) :
		x(x_),
		y(y_),
		radius(radius_)
	{
	}

	virtual ~CircleCollider() {}

	ColliderType GetType()const { return Collider_Circle; }

	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetRadius()const { return radius; }

private:
	float x;
	float y;
	float radius;

};
