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
	static ObjControl* Instance()
	{
		static ObjControl instance;
		return &instance;
	}
	~ObjControl() 
	{ 
		for (auto& obj : objects)
		{
			delete obj;
		}
	};
	void Update();
	void Draw();

	void CollisionUpdate();
	void CreateBackGround();
	void CreatePlayer(float posX_, float posY_);
	void CreateBullet(float posX_,float posY_);
	void CreateEnemy(float posX_, float posY_);
private:
	std::vector<ObjBase*> objects;
	FlexibleCollision collision;
	//Player player;
};
