#include"Enemy.h"
#include"TextureManager.h"
#include"DxLib.h"
void Enemy::Update()
{
	if (pos.x < 0 || pos.x>640 || pos.y < 0 || pos.y>480)
	{
		usingFlag = false;
	}
	pos.x--;
}

void Enemy::Draw()
{
	if (usingFlag)
	{
		DrawGraph(pos.x, pos.y, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
}
