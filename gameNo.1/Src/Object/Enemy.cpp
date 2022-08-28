#include"Enemy/Enemy.h"
#include"../TextureManager.h"
#include"DxLib.h"
#include"../Object/Player/Player.h"
void Enemy::Update()
{
	if (posX < 0 || posX>640 || posY < 0 || posY>480)
	{
		usingFlag = false;
	}
	posX -= speed;
	colType->UpdatePos(posX, posY);
}

void Enemy::Draw()
{
	if (usingFlag)
	{
		DrawGraph(posX, posY, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
}

void Enemy::OnCollision(ObjBase* obj_)
{
	if (obj_->GetObjGroup() == ObjGroup::Group_Player)
	{
		usingFlag = false;
	}
	return;
}
