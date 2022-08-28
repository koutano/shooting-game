#include"ObjControl.h"
#include"Player/Player.h"
#include"Player/Bullet.h"
#include"BackGround.h"
#include"Enemy/Enemy.h"
void ObjControl::Update()
{	
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Update();
	}
	for (auto itr = objects.begin(), itr_end = objects.end(); itr != objects.end();)
	{
		if ((*itr)->GetUsingFlag() == false)
		{
			delete* itr;
			itr = objects.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}
void ObjControl::Draw()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}

}
void ObjControl::CollisionUpdate()
{
	for (auto* obj1 : objects)
	{
		for (auto* obj2 : objects)
		{
			if (obj1 == obj2)
			{
				continue;
			}
			if (collision.Judge(*obj1->GetCollider(), *obj2->GetCollider()))
			{
				obj1->OnCollision(obj2);
			}
			
		}
	}
}
void ObjControl::CreateBackGround()
{
	objects.push_back(new BackGround());
}
void ObjControl::CreatePlayer(float posX_, float posY_)
{
	objects.push_back(new Player(posX_, posY_));
}
void ObjControl::CreateBullet(float posX_,float posY_)
{
	objects.push_back(new Bullet(posX_+20,posY_+100));
}
void ObjControl::CreateEnemy(float posX_, float posY_)
{
	objects.push_back(new Enemy(posX_, posY_, 5));
}
