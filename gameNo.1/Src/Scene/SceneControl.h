
#ifndef SCENE_CONTROL_H
#define SCENE_CONTROL_H


#include"BaseScene.h"
#include"SceneTitle.h"
//シーン制御クラス
class SceneControl
{
public:
	static SceneControl* Instance()
	{
		static SceneControl instance;
		return& instance;
	}
private:
	SceneControl() :
		nextSceneKind(SceneKind::Scene_Title)
	{
		scene = new SceneTitle;
	}

	SceneControl(SceneControl& instance) = delete;
	~SceneControl()
	{
		SceneControl(Instance);
	}

public:
	//各シーンの更新関数
	void GameProcessing();
	//各シーンの描画関数
	void DrawProcessing();


private:
	//シーン格納用
	BaseScene* scene;
	SceneKind nextSceneKind;
};

#endif // !SCENE_CONTROL_H
