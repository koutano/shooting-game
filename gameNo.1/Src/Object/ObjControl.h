#pragma once
#include"ObjBase.h"
#include<vector>
#include"../Collision/FlexibleCollision.h"
//�I�u�W�F�N�g�̃C���X�^���X�����N���X
//���ׂẴI�u�W�F�N�g�̃A�b�v�f�[�g�A�`����s��
//�I�u�W�F�N�g�͂����Ŋ֐�������Đ�������
class ObjControl
{
public:
	ObjControl() {};
	////�V���O���g��
	//static ObjControl* Instance()
	//{
	//	static ObjControl instance;
	//	return &instance;
	//}
	//�f�X�g���N�^
	~ObjControl() 
	{ 
		for (auto& obj : objects)
		{
			delete obj;
		}
	};
	//�X�V�p
	void Update();
	//�`��p
	void Draw();
	//�����蔻��X�V�p
	void CollisionUpdate();

	//�I�u�W�F�N�g�����p�֐�
	//BackGround����
	void CreateBackGround();
	/*
	Player����
	����
	1:posX(float)
	2:posY(float)
	*/
	void CreatePlayer(float posX_, float posY_);
	/*
	Bullet����
	����
	1:posX(float)
	2:posY(float)
	*/
	void CreateBullet(float posX_,float posY_);
	/*
	Enemy����
	����
	1:posX(float)
	2:posY(float)�@�@�@
	*/
	void CreateEnemy(float posX_, float posY_);
private:
	//�I�u�W�F�N�g�i�[�p�@
	std::vector<ObjBase*> objects;
	//�����蔻��
	FlexibleCollision collision;
	//Player player;
};
