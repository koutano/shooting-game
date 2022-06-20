#include "DxLib.h"
#include<map>
#include<string>
#include"TextureManager.h"
#include"KeyboardController.h"
#include"Object/ObjControl.h"
#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/BackGround.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	
	return 0;				// �\�t�g�̏I�� 
}