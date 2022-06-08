#include"BackGround.h"
#include"DxLib.h"
#include"TextureManager.h"

void BackGround::Update()
{

}

void BackGround::Draw()
{
	if (usingFlag)
	{
		DrawExtendGraph(pos.x, pos.y, 640, 480, TextureManager::Instance()->GetHandle(textureKeyword), true);

	}
}
