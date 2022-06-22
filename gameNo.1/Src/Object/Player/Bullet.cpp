#pragma once
#include"Bullet.h"
#include"../../TextureManager.h"
#include"DxLib.h"

void Bullet::Update()
{
	if (posX < 0 || posX>640 || posY < 0 || posY>480)
	{
		usingFlag = false;
	}
	posX++;
	colType->UpdatePos(posX, posY);
}

void Bullet::Draw()
{
	if (usingFlag)
	{
		DrawGraph(posX , posY, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
}

void Bullet::OnCollision(ObjBase* obj_)
{
	if (obj_->GetObjGroup() == Group_Enemy)
	{
		usingFlag = false;
	}
	return;
}