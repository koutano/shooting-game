#pragma once

//当たり判定の形状
enum ColliderType
{
	Collider_Non=-1,
	Collider_Circle,
	Collider_Rect,

	ColliderTypeNum
};

//形状基底クラス
class Collider
{
public:
	Collider() {};
	Collider(float x_, float y_):
		x(x_),
		y(y_)
	{
	}
	virtual ~Collider() {};
	void UpdatePos(float posX_, float posY_) { x = posX_; y = posY_; }
	virtual ColliderType GetType()const = 0;
protected:
	float x;
	float y;
};

