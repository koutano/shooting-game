#pragma once
#include"../RectObjBase.h"

class EnemyBase :public RectObjBase
{
public:
	EnemyBase(float posX_,float posY_,float width_,float height_,std::string keyword_) :
		RectObjBase(posX_,posY_,width_,height_,keyword_,Group_Enemy)
	{
	}
	

protected:


};