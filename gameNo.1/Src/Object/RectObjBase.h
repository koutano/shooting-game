#pragma once
#include"ObjBase.h"
#include"../Collision/RectCollider.h"
#include"string"
//矩形オブジェクトスーパークラス
class RectObjBase :public ObjBase
{
public:
	/*
		コンストラクタ
		引数
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
		コンストラクタ
		引数
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
		コンストラクタ
		引数
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
	//デストラクタ
	~RectObjBase()override {}
protected:

};
