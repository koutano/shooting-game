#pragma once
#include<string>
#include"../Collision/Collider.h"
enum ObjGroup
{
	Group_Non = -1,
	Group_Player,
	Group_Enemy,

	Group_Num
};

//�I�u�W�F�N�g���N���X
class ObjBase
{
public:
	//�R���X�g���N�^
	//�����@float�^���W X,Y
	ObjBase(float posX_,float posY_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(Group_Non),
		col()
	{
	}

	//�R���X�g���N�^
	//��1����  float�^���W
	//��2�����@�I�u�W�F�N�g�̖��O
	ObjBase(float posX_,float posY_, std::string keyword) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword),
		group(Group_Non),
		col()
	{
	}


	ObjBase(float posX_, float posY_, std::string keyword, ObjGroup group_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword),
		group(group_),
		col()
	{
	}
	virtual ~ObjBase() {}

	//�I�u�W�F�N�g�X�V�p
	virtual void Update() = 0;
	//�I�u�W�F�N�g�`��p
	virtual void Draw() = 0;
	//usingFlags�擾�p
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag�ύX�p
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

	virtual void OnCollision(ObjBase* obj_) = 0;

	Collider* GetCollider() { return col; }

	ObjGroup GetObjGroup() { return group; }
protected:
	float posX;
	float posY;
	bool usingFlag;		//�g���邩�ǂ���
	//�I�u�W�F�N�g�̖��O
	std::string textureKeyword;		
	ObjGroup group;
	Collider* col;
};