#pragma once

//�����蔻��̌`��
enum ColliderType
{
	Collider_Non=-1,
	Collider_Circle,
	Collider_Rect,

	ColliderTypeNum
};

//�`����N���X
class Collider
{
public:
	Collider() {};

	virtual ~Collider() {};
	virtual ColliderType GetType()const = 0;
};

