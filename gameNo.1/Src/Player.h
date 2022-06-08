#pragma once
#include"ObjBase.h"
#include<vector>
class Player :public ObjBase
{
public:
	Player(Vector2 pos_) :
		ObjBase(pos_, "Player")
	{
		
	}

	~Player() 
	{

	}

	void Update()override;
	void Draw()override;
	
	//const Vector2 GetPos() { return pos; }

private:

private:
	std::vector < ObjBase* > bullets;
	
};