#pragma once
#include"../RectObjBase.h"
#include<vector>
#include"../../Collision/Collider.h"
class Player :public RectObjBase
{
public:
	Player(float posX_,float posY_) :
		RectObjBase(posX_,posY_, 200, 200, "Player",Group_Player)
	{

	}

	~Player() override { delete colType; }
	

	void Update()override;
	void Draw()override;
	void OnCollision(ObjBase* obj_)override;
	//const Vector2 GetPos() { return pos; }

private:

};