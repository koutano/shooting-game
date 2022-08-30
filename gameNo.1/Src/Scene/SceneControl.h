
#ifndef SCENE_CONTROL_H
#define SCENE_CONTROL_H


#include"BaseScene.h"
#include"SceneTitle.h"
//�V�[������N���X
class SceneControl
{
public:
	static SceneControl* Instance()
	{
		static SceneControl instance;
		return& instance;
	}
private:
	SceneControl() :
		nextSceneKind(SceneKind::Scene_Title)
	{
		scene = new SceneTitle;
	}

	/*
	* ����܂��Ȃ�
	SceneControl(SceneControl& instance) = delete;
	*/
	
	~SceneControl()
	{
		delete scene;
	}

public:
	//�e�V�[���̍X�V�֐�
	void GameProcessing();
	//�e�V�[���̕`��֐�
	void DrawProcessing();


private:
	//�V�[���i�[�p
	BaseScene* scene;
	SceneKind nextSceneKind;
};

#endif // !SCENE_CONTROL_H
