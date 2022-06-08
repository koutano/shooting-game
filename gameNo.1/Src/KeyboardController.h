#ifndef KEYBOARD_CONTROLLER_H_
#define KEYBOARD_CONTROLLER_H_

class KeyboardController
{
public:
	struct KeyState
	{
		// �L�[��� => �����ꂽ or ������Ă��Ȃ�
		bool IsPrevPushed;		// 1�t���[���O�̃L�[���
		bool IsCurrentPushed;	// ���̃t���[���̃L�[���
	};

	static const int MaxKey = 256;

	static KeyboardController* Instance()
	{
		static KeyboardController instance;
		return &instance;
	}

public:
	void Update();
	bool IsPushed(int key);
	bool IsHeld(int key);
	bool IsReleased(int key);

private:
	KeyboardController() 
	{
		memset(KeyStates, false, sizeof(KeyState) * MaxKey);
	}

	KeyboardController(KeyboardController& instance) = delete;
private:
	KeyState KeyStates[MaxKey];
};

#endif
