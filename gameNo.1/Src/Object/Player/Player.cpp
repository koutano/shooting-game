#include"Player.h"
#include"../../TextureManager.h"
#include"../../KeyboardController.h"
#include"DxLib.h"
#include"Bullet.h"
#include"../../Collision/FlexibleCollision.h"
#include"../ObjControl.h"
void Player::Update()
{
	//ˆÚ“®ˆ—
	{
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_W))
		{
			posY--;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_S))
		{
			posY++;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_A))
		{
			posX--;
		}
		if (KeyboardController::Instance()->IsHeld(KEY_INPUT_D))
		{
			posX++;
		}
	}
	//‹…‚¾‚µ‚Ü‚·
	if (KeyboardController::Instance()->IsPushed(KEY_INPUT_P))
	{
		ObjControl::Instance()->CreateBullet(posX, posY);
	} 
	const RectCollider &r1 = static_cast<const RectCollider>(colType);
	r1.

}

void Player::Draw()
{
	if (usingFlag)
	{
		DrawGraph(posX, posY, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
	
}

void Player::OnCollision(ObjBase* obj_)
{
	if (obj_->GetObjGroup() == Group_Enemy)
	{
		usingFlag = false;
	}
}