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

	virtual ~Collider() {};
	virtual ColliderType GetType()const = 0;
};

