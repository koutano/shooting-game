#include"SceneControl.h"
#include"SceneTitle.h"
#include"SceneGame.h"

void SceneControl::GameProcessing()
{
	if (scene->GetSceneKind() != nextSceneKind)
	{
		delete scene;
		switch (nextSceneKind)
		{
		case SceneKind::Scene_Title:
			scene = new SceneTitle;
			break;
		case SceneKind::Scene_Game:
			scene = new SceneGame;
			break;
		default:
			break;
		}
	}
	nextSceneKind = scene->Update();
}

void SceneControl::DrawProcessing()
{
	scene->Draw();
}