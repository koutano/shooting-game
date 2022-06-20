#include"BackGround.h"
#include"DxLib.h"
#include"../TextureManager.h"

void BackGround::Update()
{

}

void BackGround::Draw()
{
	if (usingFlag)
	{
		DrawExtendGraph(posX, posY, 640, 480, TextureManager::Instance()->GetHandle(textureKeyword), true);
	}
}

void BackGround::OnCollision(ObjBase *obj_)
{

}
