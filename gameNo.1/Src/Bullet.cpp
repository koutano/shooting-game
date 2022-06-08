#pragma once
#include"Bullet.h"
#include"TextureManager.h"
#include"DxLib.h"

void Bullet::Update()
{
	if (pos.x < 0 || pos.x>640 || pos.y < 0 || pos.y>480)
	{
		usingFlag = false;
	}
	pos.x++;
}

void Bullet::Draw()
{
	if (usingFlag)
	{
		DrawGraph(pos.x + 2  , pos.y, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
}