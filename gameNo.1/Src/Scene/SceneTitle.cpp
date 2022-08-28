#include"SceneTitle.h"
#include"../KeyboardController.h"
#include"DxLib.h"
SceneKind SceneTitle::Update()
{
	//objects->CreateBackGround();
	if (KeyboardController::Instance()->IsPushed(KEY_INPUT_RETURN))
	{
		return SceneKind::Scene_Game;
	}
	objects.Update();
	return GetSceneKind();
}

void SceneTitle::Draw()
{
	objects.Draw();
}