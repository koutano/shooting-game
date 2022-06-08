#include "DxLib.h"
#include<map>
#include<string>
#include"TextureManager.h"
#include"KeyboardController.h"

#include"Player.h"
#include"Enemy.h"
#include"BackGround.h"

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


	Player player(Vector2(0,0));
	Enemy enemy(Vector2(640, 240));
	BackGround bg(Vector2(0,0));

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		ClearDrawScreen();

		KeyboardController::Instance()->Update();

		player.Update();
		enemy.Update();
		bg.Update();

		bg.Draw();
		player.Draw();
		enemy.Draw();

		ScreenFlip();

	}

	TextureManager::Instance()->AllDelete();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	
	return 0;				// �\�t�g�̏I�� 
}