#pragma once
#include<string>
#include"../Collision/Collider.h"
/*
�I�u�W�F�N�g�O���[�v�I�ʗp
*/
enum class ObjGroup
{
	Group_Non = -1,
	Group_Player,
	Group_Enemy,

	Group_Num
};
/*
	ObjBase��width��height������̂͂悭�Ȃ�
	�iCircleObjBase�Ɉڍs�����Ƃ��ɕs�v�ɂȂ�j
*/
//�I�u�W�F�N�g���N���X
class ObjBase
{
public:
	//�R���X�g���N�^
	//�����@float�^���W X,Y
	ObjBase(float posX_, float posY_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(ObjGroup::Group_Non)
		//colType(Collider_Non)
	{
	}

	//�R���X�g���N�^
	//��1����  float�^���W
	//��2�����@�I�u�W�F�N�g�̖��O
	ObjBase(float posX_, float posY_, std::string keyword_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword_),
		group(ObjGroup::Group_Non)
		//colType(Collider_Non)
	{
	}

	ObjBase(float posX_, float posY_, ObjGroup group_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(group_)
		//colType(Collider_Non)
	{
	}

	ObjBase(float posX_, float posY_, std::string keyword_, ObjGroup group_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword_),
		group(group_)
		//colType(Collider_Non)
	{
	}
	virtual ~ObjBase() {}

	//�I�u�W�F�N�g�X�V�p
	virtual void Update() = 0;
	//�I�u�W�F�N�g�`��p
	virtual void Draw() = 0;

	float GetPosX() { return posX; }
	float GetPosY() { return posY; }

	//usingFlags�擾�p
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag�ύX�p
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

	virtual void OnCollision(ObjBase* obj_) = 0;

	//ColliderType GetColType() { return colType; }
	Collider* GetCollider() { return colType; }

	ObjGroup GetObjGroup() { return group; }
protected:
	float posX;
	float posY;
	bool usingFlag;		//�g���邩�ǂ���
	//�I�u�W�F�N�g�̖��O
	std::string textureKeyword;
	ObjGroup group;
	Collider* colType;
	//ColliderType colType;
};