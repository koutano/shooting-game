#pragma once
#include"EnemyBase.h"
//�G�N���X
class Enemy :public EnemyBase
{
public:
	/*
	�R���X�g���N�^
	����
	1:�������WX(float)
	2:�������WY(float)
	3:���x(float)
	*/
	Enemy(float posX_,float posY_,float speed_):
		EnemyBase(posX_,posY_,200,200,"Enemy"),
		speed(speed_)
	{

	}
	//�f�X�g���N�^
	~Enemy()override { delete colType; }
	//�X�V�p
	void Update()override;
	//�`��p
	void Draw()override;
	//�����莞����
	void OnCollision(ObjBase* obj_)override;

private:
	float speed;
};
