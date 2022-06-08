#pragma once
#include"Collider.h"
#include"Mathematics.h"
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
	CircleAndRect() {}

	virtual ~CircleAndRect() {}

	bool Judge(const Collider& col1, const Collider& col2)
	{
		
	}
};

//��`�Ƌ�`�̓����蔻��
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
		//2�_�Ԃ̒���
		float currentDistance = Length(Vector2(r1.GetX(), r1.GetY()), Vector2(r2.GetX(), r2.GetY()));

	}
};
