#pragma once

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


	void GameProcessing();
	void DrawProcessing();

private: 
	//
	SceneControl()
	{
	}

	SceneControl(SceneControl* instance) = delete;

};