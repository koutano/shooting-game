#pragma once
#include"ObjBase.h"
#include"../Collision/RectCollider.h"
#include"string"
class RectObjBase :public ObjBase
{
public:
	RectObjBase(float posX_, float posY_, float width_, float height_) :
		ObjBase(posX_, posY_, width_, height_)
	{
		colType = new RectCollider(posX, posY, width, height);
	}

	RectObjBase(float posX_, float posY_, float width_, float height_, std::string keyword_) :
		ObjBase(posX_, posY_, width_, height_, keyword_)
	{
		colType = new RectCollider(posX, posY, width, height);
	}

	RectObjBase(float posX_, float posY_, float width_, float height_, std::string keyword_, ObjGroup group_) :
		ObjBase(posX_, posY_, width_, height_, keyword_, group_)
	{
		colType = new RectCollider(posX, posY, width, height);
	}

	~RectObjBase()override {}
protected:

};
