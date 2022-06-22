#pragma once
#include"Collider.h"
//‰~Œ`óƒNƒ‰ƒX
class CircleCollider :public Collider
{
public:
	CircleCollider(float x_, float y_, float radius_) :
		Collider(x_, y_),
		radius(radius_)
	{
	}

	virtual ~CircleCollider() {}

	ColliderType GetType()const { return Collider_Circle; }

	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetRadius()const { return radius; }

private:
	float radius;

};
