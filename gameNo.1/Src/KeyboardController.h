#pragma once
class KeyboardController
{
public:
	//キー情報取得用
	struct KeyState
	{
		// キー情報 => 押された or 押されていない
		bool IsPrevPushed;		// 1フレーム前のキー情報
		bool IsCurrentPushed;	// 今のフレームのキー情報
	};

	static const int MaxKey = 256;
	//シングルトン
	static KeyboardController* Instance()
	{
		static KeyboardController instance;
		return &instance;
	}

public:
	//キー情報更新用
	void Update();
	//キーを押した瞬間かどうか
	bool IsPushed(int key);
	//キーを押しているかどうか
	bool IsHeld(int key);
	//キーを話した瞬間かどうか
	bool IsReleased(int key);

private:
	//コンストラクタ
	KeyboardController() 
	{
		memset(KeyStates, false, sizeof(KeyState) * MaxKey);
	}
private:
	//キーの状態保存用
	KeyState KeyStates[MaxKey];
};
