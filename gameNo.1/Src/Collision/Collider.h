#pragma once

//�����蔻��̌`��
enum ColliderType
{
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

