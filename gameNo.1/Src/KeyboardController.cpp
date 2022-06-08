#include "DxLib.h"
#include "KeyboardController.h"

void KeyboardController::Update()
{
	char buffer[256];

	// DxLib����L�[�{�[�h�̓��͏���S�Ď擾
	if (GetHitKeyStateAll(buffer) != 0)
	{
		return;
	}

	for (int i = 0; i < MaxKey; i++)
	{
		// 1�t���[���O��Current���������Prev�Ƃ��Ĉ���
		KeyStates[i].IsPrevPushed = KeyStates[i].IsCurrentPushed;

		// buffer�̏�񂩂�Current���X�V����
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

