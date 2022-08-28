#pragma once
#include"../RectObjBase.h"
//エネミー用スーパークラス
class EnemyBase :public RectObjBase
{
public:
	/*
	コンストラクタ
	引数
	1:初期座標X(float)
	2:初期座標Y(float)
	3:横幅(float)
	4:縦幅(float)
	5:keyword(string)
	*/
	EnemyBase(float posX_,float posY_,float width_,float height_,std::string keyword_) :
		RectObjBase(posX_,posY_,width_,height_,keyword_,ObjGroup::Group_Enemy)
	{
	}
	

protected:


};