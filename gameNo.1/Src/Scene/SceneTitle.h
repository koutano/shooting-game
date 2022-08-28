#pragma once
#include"BaseScene.h"
#include"../Object/ObjControl.h"

class SceneTitle :public BaseScene
{
public:
	SceneTitle():
		BaseScene(SceneKind::Scene_Title)
	{
		objects.CreateBackGround();
	}

	~SceneTitle()override
	{
	}

	SceneKind Update()override;
	void Draw()override;
private:
	ObjControl objects;
};