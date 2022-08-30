#pragma once
class KeyboardController
{
public:
	//�L�[���擾�p
	struct KeyState
	{
		// �L�[��� => �����ꂽ or ������Ă��Ȃ�
		bool IsPrevPushed;		// 1�t���[���O�̃L�[���
		bool IsCurrentPushed;	// ���̃t���[���̃L�[���
	};

	static const int MaxKey = 256;
	//�V���O���g��
	static KeyboardController* Instance()
	{
		static KeyboardController instance;
		return &instance;
	}

public:
	//�L�[���X�V�p
	void Update();
	//�L�[���������u�Ԃ��ǂ���
	bool IsPushed(int key);
	//�L�[�������Ă��邩�ǂ���
	bool IsHeld(int key);
	//�L�[��b�����u�Ԃ��ǂ���
	bool IsReleased(int key);

private:
	//�R���X�g���N�^
	KeyboardController() 
	{
		memset(KeyStates, false, sizeof(KeyState) * MaxKey);
	}
private:
	//�L�[�̏�ԕۑ��p
	KeyState KeyStates[MaxKey];
};
