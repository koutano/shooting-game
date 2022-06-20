#pragma once
#include"Collider.h"
#include"CircleCollider.h"
#include"RectCollider.h"
#include"../Mathematics.h"
#include<math.h>
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
public:
	CircleAndCircle() {}

	virtual ~CircleAndCircle() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != Collider_Circle
			|| col2.GetType() != Collider_Circle)
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
public:
	CircleAndRect() {}

	virtual ~CircleAndRect() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != Collider_Circle
			|| col2.GetType() != Collider_Rect)
		{
			return false;
		}
		const CircleCollider& c = static_cast<const CircleCollider&>(col1);
		const RectCollider& r = static_cast<const RectCollider&>(col2);

		float L = r.GetX();
		float R = r.GetX() + r.GetWidth();
		float T = r.GetY();
		float B = r.GetY() + r.GetHeight();

		if (L - c.GetRadius() > c.GetX() ||
			R + c.GetRadius() < c.GetX() ||
			T - c.GetRadius() > c.GetY() ||
			B + c.GetRadius() < c.GetY())
		{//矩形に円の半径分を足した範囲
			return false;
		}
		if (L > c.GetX() && T > c.GetY() &&
			!(Length(Vector2(L,T),Vector2(c.GetX(),c.GetY())) < c.GetRadius()))
		{//左上の当たり判定
			return false;
		}
		if (R < c.GetX() && T > c.GetY() &&
			!(Length(Vector2(R, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//右上の当たり判定
			return false;
		}
		if (L > c.GetX() && B < c.GetY() &&
			!(Length(Vector2(L, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//左下の当たり判定
			return false;
		}
		if (R < c.GetX() && B < c.GetY() &&
			!(Length(Vector2(R, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//右下の当たり判定
			return false;
		}
		return true;//すべての条件が外れたときに当たっている	
	}
};

	//矩形と円の当たり判定
class RectAndCircle :public Collision
{
public:
	RectAndCircle() {}

	virtual ~RectAndCircle() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != Collider_Rect
			|| col2.GetType() != Collider_Circle)
		{
			return false;
		}
		const RectCollider& r = static_cast<const RectCollider&>(col1);
		const CircleCollider& c = static_cast<const CircleCollider&>(col2);

		float L = r.GetX();
		float R = r.GetX() + r.GetWidth();
		float T = r.GetY();
		float B = r.GetY() + r.GetHeight();

		if (L - c.GetRadius() > c.GetX() ||
			R + c.GetRadius() < c.GetX() ||
			T - c.GetRadius() > c.GetY() ||
			B + c.GetRadius() < c.GetY())
		{//矩形に円の半径分を足した範囲
			return false;
		}
		if (L > c.GetX() && T > c.GetY() &&
			!(Length(Vector2(L, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//左上の当たり判定
			return false;
		}
		if (R < c.GetX() && T > c.GetY() &&
			!(Length(Vector2(R, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//右上の当たり判定
			return false;
		}
		if (L > c.GetX() && B < c.GetY() &&
			!(Length(Vector2(L, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//左下の当たり判定
			return false;
		}
		if (R < c.GetX() && B < c.GetY() &&
			!(Length(Vector2(R, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//右下の当たり判定
			return false;
		}
		return true;//すべての条件が外れたときに当たっている	
	}
};


	//矩形と矩形の当たり判定
class RectAndRect :public Collision
{
public:
	RectAndRect() {}

	virtual ~RectAndRect() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		if (col1.GetType() != Collider_Rect
			|| col2.GetType() != Collider_Rect)
		{
			return false;
		}
		const RectCollider& r1 = static_cast<const RectCollider&>(col1);
		const RectCollider& r2 = static_cast<const RectCollider&>(col2);

		//中心座標
		Vector2 center1 = {
			r1.GetX() + (r1.GetWidth() / 2.0f),
			r1.GetY() + (r1.GetHeight() / 2.0f)
		};
		Vector2 center2 = {
			r2.GetX() + (r2.GetWidth() / 2.0f),
			r2.GetY() + (r2.GetHeight() / 2.0f)
		};
		//当たり判定処理 
		if (fabsf(center1.x - center2.x) > (r1.GetWidth() + r2.GetWidth()) / 2.0f ||
			fabsf(center1.y - center2.y) > (r1.GetHeight() + r2.GetHeight()) / 2.0f)
		{
			return false;
		}
		return true;
	}

};

	