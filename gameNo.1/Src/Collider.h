#pragma once

//当たり判定の形状
enum ColliderType
{
	ColliderTypeCircle,
	ColliderTypeRect,

	ColliderTypeNum
};

//形状基底クラス
class Collider
{
public:
	virtual ~Collider() {};

	virtual ColliderType GetType()const = 0;
};

//円形状クラス
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

	ColliderType GetType()const { return ColliderTypeCircle; }

	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetRadius()const { return radius; }

private:
	float x;
	float y;
	float radius;

};

//矩形状クラス
class RectCollider :public Collider
{
public:
	RectCollider(float left_, float bottom_, float right_, float top_) :
		left(left_),
		bottom(bottom_),
		right(right_),
		top(top_)
	{
	}

	virtual ~RectCollider() {}

	ColliderType GetType()const { return ColliderTypeRect; }

	float GetLeft()const { return left; }
	float GetBottom()const { return bottom; }
	float GetRight()const { return right; }
	float GetTop()const { return top; }

private:
	float left;
	float bottom;
	float right;
	float top;
};