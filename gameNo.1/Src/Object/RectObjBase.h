#pragma once
#include"ObjBase.h"
#include"../Collision/RectCollider.h"
#include"string"
class RectObjBase :public ObjBase
{
public:
	RectObjBase(float posX_, float posY_, float width_, float height_) :
		ObjBase(posX_, posY_)
	{
		col = new RectCollider(posX, posY, width_, height_);
	}

	RectObjBase(float posX_,float posY_, float width_, float height_,std::string keyword_) :
		ObjBase(posX_,posY_,keyword_)
	{
		col = new RectCollider(posX, posY, width_, height_);
	}

	RectObjBase(float posX_, float posY_, float width_, float height_, std::string keyword_, ObjGroup group_) :
		ObjBase(posX_, posY_, keyword_, group_)
	{
		col = new RectCollider(posX, posY, width_, height_);
	}

	~RectObjBase()override {}
protected:
	
};
