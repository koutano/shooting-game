#pragma once
#include"ObjBase.h"
#include"../Collision/RectCollider.h"
#include"string"
//��`�I�u�W�F�N�g�X�[�p�[�N���X
class RectObjBase :public ObjBase
{
public:
	/*
		�R���X�g���N�^
		����
		1:posX(float)
		2:posY(float)
		3:width(float)
		4:height(float)
	*/
	RectObjBase(float posX_, float posY_, float width_, float height_) :
		ObjBase(posX_, posY_)
	{
		colType = new RectCollider(posX, posY, width_, height_);
	}
	/*
		�R���X�g���N�^
		����
		1:posX(float)
		2:posY(float)
		3:width(float)
		4:height(float)
		5:keyword(string)
	*/
	RectObjBase(float posX_, float posY_, float width_, float height_, std::string keyword_) :
		ObjBase(posX_, posY_, keyword_)
	{
		colType = new RectCollider(posX, posY, width_, height_);
	}

	/*
		�R���X�g���N�^
		����
		1:posX(float)
		2:posY(float)
		3:width(float)
		4:height(float)
		5:keyword(string)
		6:group(ObjGroup)
	*/
	RectObjBase(float posX_, float posY_, float width_, float height_, std::string keyword_, ObjGroup group_) :
		ObjBase(posX_, posY_, keyword_, group_)
	{
		colType = new RectCollider(posX, posY, width_, height_);
	}
	//�f�X�g���N�^
	~RectObjBase()override {}
protected:

};
