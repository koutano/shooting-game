#include"Player.h"
#include"TextureManager.h"
#include"KeyboardController.h"
#include"DxLib.h"
#include"Bullet.h"
void Player::Update()
{
	//ˆÚ“®ˆ—
	{
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_W))
		{
			pos.y--;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_S))
		{
			pos.y++;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_A))
		{
			pos.x--;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_D))
		{
			pos.x++;
		}
	}
	//‹…‚¾‚µ‚Ü‚·
	{
		if (KeyboardController::Instance()->IsPushed(KEY_INPUT_P))
		{
			bullets.push_back(new Bullet(pos));
		}
	}

	for (auto* bullet : bullets)
	{
		bullet->Update();
	}
	for (auto itr = bullets.begin(), itr_end = bullets.end(); itr != bullets.end();)
	{
		if ((*itr)->GetUsingFlag() == false)
		{
			delete* itr;
			itr = bullets.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

void Player::Draw()
{
	if (usingFlag)
	{
		DrawGraph(pos.x, pos.y, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
	for (auto* bullet : bullets)
	{
		bullet->Draw();
	}
}

