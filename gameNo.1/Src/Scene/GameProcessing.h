#pragma once

class GameProcessing
{
public:
	static GameProcessing* Instance()
	{
		static GameProcessing instance;
		return &instance;
	}

	~GameProcessing()
	{

	}

private:
	GameProcessing()
	{
	}

	GameProcessing(GameProcessing* instance) = delete;

private:


};