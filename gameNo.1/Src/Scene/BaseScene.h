#pragma once

//シーンの種類
enum class SceneKind
{
	Scene_Title,
	Scene_Game,

};

class BaseScene
{
public:
	//コンストラクタ
	BaseScene(SceneKind sceneKind_):
	currentSceneKind(sceneKind_)
	{};
	//デストラクタ
	virtual ~BaseScene() {};
	//更新用　
	virtual SceneKind Update() = 0;
	//描画用
	virtual void Draw() = 0; 
	//現在のシーン取得用
	const SceneKind GetSceneKind() { return currentSceneKind; }
protected:
	//現在のシーンの種類
	SceneKind currentSceneKind;

};