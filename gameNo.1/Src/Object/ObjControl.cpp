#include"ObjControl.h"
#include"Player/Player.h"
#include"Player/Bullet.h"
#include"BackGround.h"
#include"Enemy/Enemy.h"
void ObjControl::Update()
{	
	for (auto* obj : objects)
	{
		obj->Update();
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
	for (auto* obj : objects)
	{
		obj->Draw();
	}
}
void ObjControl::CollisionUpdate()
{
	//for (auto itr1 = objects.begin(), itr_end = objects.end(); itr1 != objects.end();)
	//{
	//	for (auto itr2 = objects.begin(), itr_end = objects.end(); itr2 != objects.end();)
	//	{
	//		if (collision.Judge(*(*itr1)->GetCollider(), *(*itr2)->GetCollider()))
	//		{
	//			if (itr1 != itr2 && (*itr1)->GetUsingFlag() && (*itr2)->GetUsingFlag())
	//			{
	//				(*itr1)->OnCollision((*itr2));
	//			}
	//			/*if (itr1 == itr2)
	//			{
	//				return;
	//			}
	//			if (!(*itr1)->GetUsingFlag() || !(*itr2)->GetUsingFlag())
	//			{
	//				return;
	//			}
	//			(*itr1)->OnCollision(*itr2);*/
	//		}
	//	}
	//}

	for (auto* obj1 : objects)
	{
		for (auto* obj2 : objects)
		{
			if (obj1 != obj2 && obj1->GetUsingFlag() && obj2->GetUsingFlag())
			{

				if (collision.Judge(*obj1->GetCollider(), *obj2->GetCollider()))
				{

					obj1->OnCollision(obj2);

					/*if (obj1 == obj2)
					{
						break;
					}
					if (!obj1->GetUsingFlag() || !obj2->GetUsingFlag())
					{
						return;
					}*/

				}
			}
		}
	}
}
void ObjControl::CreateBackGround()
{
	objects.push_back(new BackGround(0, 0));
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
	objects.push_back(new Enemy(posX_, posY_, 1));
}
