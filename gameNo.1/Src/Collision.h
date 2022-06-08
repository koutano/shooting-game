#pragma once
#include"Collider.h"
#include"Mathematics.h"
//当たり判定基底クラス
class Collision
{
public:
	virtual ~Collision() {};

	virtual bool Judge(const Collider& col1, const Collider& col2) = 0;
};

//円と円の当たり判定
class CircleAndCircle :public Collision
{
	CircleAndCircle() {}

	virtual ~CircleAndCircle() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != ColliderTypeCircle
			|| col2.GetType() != ColliderTypeCircle)
		{
			return false;
		}
		const CircleCollider& c1 = static_cast<const CircleCollider&>(col1);
		const CircleCollider& c2 = static_cast<const CircleCollider&>(col2);
		
		//2点間の長さ
		float currentDistance = Length(Vector2(c1.GetX(), c1.GetY()), Vector2(c2.GetX(), c2.GetY()));

		//衝突判定距離
		float judgeDistance = c1.GetRadius() + c2.GetRadius();

		//当たっていない=現在の距離が衝突判定距離より長いとき
		if (judgeDistance < currentDistance)
		{
			return false;
		}
		return true;
	}
};

//円と矩形の当たり判定
class CircleAndRect :public Collision
{
	CircleAndRect() {}

	virtual ~CircleAndRect() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		
	}
};

//矩形と矩形の当たり判定
class RectAndRect :public Collision
{
	RectAndRect() {}

	virtual ~RectAndRect() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != ColliderTypeRect
			|| col2.GetType() != ColliderTypeRect)
		{
			return false;
		}
		const RectCollider& r1 = static_cast<const RectCollider&>(col1);
		const RectCollider& r2 = static_cast<const RectCollider&>(col2);
		//2点間の長さ
		float currentDistance = Length(Vector2(r1.GetX(), r1.GetY()), Vector2(r2.GetX(), r2.GetY()));

	}
};
