#pragma once
#include"../RectObjBase.h"
//�o���b�g�N���X
class Bullet :public RectObjBase
{
public:
	/*
	�R���X�g���N�^
	����
	1:�������WX(float)
	2:�������WY(float)
	*/
	Bullet(float posX_,float posY_):
		RectObjBase(posX_,posY_,100,50,"Bullet",ObjGroup::Group_Player)
	{
	}
	//�f�X�g���N�^
	~Bullet()override { delete colType; }
	//�X�V�p
	void Update()override;
	//�`��p
	void Draw()override;
	//�����莞����
	void OnCollision(ObjBase* obj_)override;
private:


};