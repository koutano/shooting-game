#pragma once
#include"ObjBase.h"
#include<vector>
#include"../Collision/FlexibleCollision.h"
//オブジェクトのインスタンスを持つクラス
//すべてのオブジェクトのアップデート、描画を行う
//オブジェクトはここで関数を作って生成する
class ObjControl
{
public:
	static ObjControl* Instance()
	{
		static ObjControl instance;
		return &instance;
	}
	~ObjControl() 
	{ 
		for (auto& obj : objects)
		{
			delete obj;
		}
	};
	void Update();
	void Draw();

	void CollisionUpdate();
	void CreateBackGround();
	void CreatePlayer(float posX_, float posY_);
	void CreateBullet(float posX_,float posY_);
	void CreateEnemy(float posX_, float posY_);
private:
	std::vector<ObjBase*> objects;
	FlexibleCollision collision;
	//Player player;
};
