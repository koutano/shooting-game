#pragma once
#include"../RectObjBase.h"
//�G�l�~�[�p�X�[�p�[�N���X
class EnemyBase :public RectObjBase
{
public:
	/*
	�R���X�g���N�^
	����
	1:�������WX(float)
	2:�������WY(float)
	3:����(float)
	4:�c��(float)
	5:keyword(string)
	*/
	EnemyBase(float posX_,float posY_,float width_,float height_,std::string keyword_) :
		RectObjBase(posX_,posY_,width_,height_,keyword_,ObjGroup::Group_Enemy)
	{
	}
	

protected:


};