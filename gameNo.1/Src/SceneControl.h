#pragma once

enum SceneKind
{
	Scene_Title,
	Scene_Game,
	Scene_Finish,
	
	Scene_Num
};
class SceneControl
{
public:
	static SceneControl* Instance()
	{
		static SceneControl instance;
		return& instance;
	}
	
	~SceneControl()
	{
		SceneControl(Instance);
	}

	

private: 
	//
	SceneControl()
	{
	}

	SceneControl(SceneControl* instance) = delete;

};