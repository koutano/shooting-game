#pragma once
#include"BaseScene.h"
#include"../Object/ObjControl.h"
class SceneGame :public BaseScene
{
public:
	SceneGame() :
		BaseScene(SceneKind::Scene_Game)
	{
		objects.CreateBackGround();
		objects.CreatePlayer(0,0);
	}

	~SceneGame()override
	{
	}
	SceneKind Update()override;
	void Draw()override;

private:
	ObjControl objects;
};