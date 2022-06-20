#pragma once
#include"Collider.h"
#include"CircleCollider.h"
#include"RectCollider.h"
#include"../Mathematics.h"
#include<math.h>
//�����蔻����N���X
class Collision
{
public:
	virtual ~Collision() {};

	virtual bool Judge(const Collider& col1, const Collider& col2) = 0;
};

//�~�Ɖ~�̓����蔻��
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
		
		//2�_�Ԃ̒���
		float currentDistance = Length(Vector2(c1.GetX(), c1.GetY()), Vector2(c2.GetX(), c2.GetY()));

		//�Փ˔��苗��
		float judgeDistance = c1.GetRadius() + c2.GetRadius();

		//�������Ă��Ȃ�=���݂̋������Փ˔��苗����蒷���Ƃ�
		if (judgeDistance < currentDistance)
		{
			return false;
		}
		return true;
	}
};

//�~�Ƌ�`�̓����蔻��
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
		{//��`�ɉ~�̔��a���𑫂����͈�
			return false;
		}
		if (L > c.GetX() && T > c.GetY() &&
			!(Length(Vector2(L,T),Vector2(c.GetX(),c.GetY())) < c.GetRadius()))
		{//����̓����蔻��
			return false;
		}
		if (R < c.GetX() && T > c.GetY() &&
			!(Length(Vector2(R, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�E��̓����蔻��
			return false;
		}
		if (L > c.GetX() && B < c.GetY() &&
			!(Length(Vector2(L, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�����̓����蔻��
			return false;
		}
		if (R < c.GetX() && B < c.GetY() &&
			!(Length(Vector2(R, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�E���̓����蔻��
			return false;
		}
		return true;//���ׂĂ̏������O�ꂽ�Ƃ��ɓ������Ă���	
	}
};

	//��`�Ɖ~�̓����蔻��
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
		{//��`�ɉ~�̔��a���𑫂����͈�
			return false;
		}
		if (L > c.GetX() && T > c.GetY() &&
			!(Length(Vector2(L, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//����̓����蔻��
			return false;
		}
		if (R < c.GetX() && T > c.GetY() &&
			!(Length(Vector2(R, T), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�E��̓����蔻��
			return false;
		}
		if (L > c.GetX() && B < c.GetY() &&
			!(Length(Vector2(L, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�����̓����蔻��
			return false;
		}
		if (R < c.GetX() && B < c.GetY() &&
			!(Length(Vector2(R, B), Vector2(c.GetX(), c.GetY())) < c.GetRadius()))
		{//�E���̓����蔻��
			return false;
		}
		return true;//���ׂĂ̏������O�ꂽ�Ƃ��ɓ������Ă���	
	}
};


	//��`�Ƌ�`�̓����蔻��
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

		//���S���W
		Vector2 center1 = {
			r1.GetX() + (r1.GetWidth() / 2.0f),
			r1.GetY() + (r1.GetHeight() / 2.0f)
		};
		Vector2 center2 = {
			r2.GetX() + (r2.GetWidth() / 2.0f),
			r2.GetY() + (r2.GetHeight() / 2.0f)
		};
		//�����蔻�菈�� 
		if (fabsf(center1.x - center2.x) > (r1.GetWidth() + r2.GetWidth()) / 2.0f ||
			fabsf(center1.y - center2.y) > (r1.GetHeight() + r2.GetHeight()) / 2.0f)
		{
			return false;
		}
		return true;
	}

};

	