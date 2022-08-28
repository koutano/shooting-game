#pragma once
#include"../RectObjBase.h"
#include<vector>
#include"../../Collision/Collider.h"
//�v���C���[�N���X
class Player :public RectObjBase
{
public:
	/*
	�R���X�g���N�^
	����
	1:�������WX(float)
	2:�������WY(float)
	*/
	Player(float posX_,float posY_) :
		RectObjBase(posX_,posY_, 200, 200, "Player",ObjGroup::Group_Player)
	{

	}
	//�f�X�g���N�^
	~Player() override { delete colType; }
	
	//�X�V�p
	void Update()override;
	//�`��p
	void Draw()override;
	//�����莞����
	void OnCollision(ObjBase* obj_)override;

private:

};