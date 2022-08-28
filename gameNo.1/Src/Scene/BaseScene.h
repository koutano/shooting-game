#pragma once

//�V�[���̎��
enum class SceneKind
{
	Scene_Title,
	Scene_Game,

};

class BaseScene
{
public:
	//�R���X�g���N�^
	BaseScene(SceneKind sceneKind_):
	currentSceneKind(sceneKind_)
	{};
	//�f�X�g���N�^
	virtual ~BaseScene() {};
	//�X�V�p�@
	virtual SceneKind Update() = 0;
	//�`��p
	virtual void Draw() = 0; 
	//���݂̃V�[���擾�p
	const SceneKind GetSceneKind() { return currentSceneKind; }
protected:
	//���݂̃V�[���̎��
	SceneKind currentSceneKind;

};