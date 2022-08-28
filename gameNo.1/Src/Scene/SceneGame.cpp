#include"SceneGame.h"
#include"../KeyboardController.h"
#include<DxLib.h>
SceneKind SceneGame::Update()
{
	if (KeyboardController::Instance()->IsPushed(KEY_INPUT_RETURN))
	{
		return SceneKind::Scene_Title;
	}
	objects.Update();
	return GetSceneKind();
}

void SceneGame::Draw()
{
	objects.Draw();
}