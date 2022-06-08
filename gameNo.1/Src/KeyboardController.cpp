#include "DxLib.h"
#include "KeyboardController.h"

void KeyboardController::Update()
{
	char buffer[256];

	// DxLibからキーボードの入力情報を全て取得
	if (GetHitKeyStateAll(buffer) != 0)
	{
		return;
	}

	for (int i = 0; i < MaxKey; i++)
	{
		// 1フレーム前のCurrent情報を今回はPrevとして扱う
		KeyStates[i].IsPrevPushed = KeyStates[i].IsCurrentPushed;

		// bufferの情報からCurrentを更新する
		KeyStates[i].IsCurrentPushed = buffer[i] != 0 ? true : false;
	}
}

bool KeyboardController::IsPushed(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (KeyStates[key].IsPrevPushed == false &&
		KeyStates[key].IsCurrentPushed == true)
	{
		return true;
	}

	return false;
}

bool KeyboardController::IsHeld(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (KeyStates[key].IsPrevPushed == true &&
		KeyStates[key].IsCurrentPushed == true)
	{
		return true;
	}

	return false;
}

bool KeyboardController::IsReleased(int key)
{
	if (key < 0 || key >= MaxKey)
	{
		return false;
	}

	if (KeyStates[key].IsPrevPushed == true &&
		KeyStates[key].IsCurrentPushed == false)
	{
		return true;
	}

	return false;
}

