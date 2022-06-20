#include "DxLib.h"
#include<map>
#include<string>
#include"TextureManager.h"
#include"KeyboardController.h"
#include"Object/ObjControl.h"
#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/BackGround.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	std::map<std::string, std::string> load_desc =
	{
		{"Player","Res/Player.png"},
		{"Enemy","Res/Enemy.png"},
		{"BackGround","Res/BackGround.png"},
		{"Bullet","Res/Bullet.png"},
	};

	for (auto itr = load_desc.begin(); itr != load_desc.end(); itr++)
	{
		if (TextureManager::Instance()->Load(itr->first, itr->second) == false)
		{
			return 0;
		}
	}


	ObjControl::Instance()->CreateBackGround();
	ObjControl::Instance()->CreatePlayer(0, 0);
	ObjControl::Instance()->CreateEnemy(640, 240);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		ClearDrawScreen();

		KeyboardController::Instance()->Update();
		if (KeyboardController::Instance()->IsPushed(KEY_INPUT_O))
		{
		}
		ObjControl::Instance()->Update();
		ObjControl::Instance()->Draw();

		ObjControl::Instance()->CollisionUpdate();

		ScreenFlip();
		 
	}

	TextureManager::Instance()->AllDelete();

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	
	return 0;				// ソフトの終了 
}