#pragma once
#include<string>
#include"../Collision/Collider.h"
/*
オブジェクトグループ選別用
*/
enum class ObjGroup : int
{
	Group_Player,
	Group_Enemy,

	Group_Num,
	Group_Non
};

//オブジェクト基底クラス
class ObjBase
{
public:
	//コンストラクタ
	//引数　float型座標 X,Y
	ObjBase(float posX_, float posY_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(ObjGroup::Group_Non),
		//colType(Collider_Non)
		colType(nullptr)
	{
	}

	//コンストラクタ
	//第1引数  float型座標
	//第2引数　オブジェクトの名前
	ObjBase(float posX_, float posY_, std::string keyword_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword_),
		group(ObjGroup::Group_Non),
		//colType(Collider_Non)
		colType(nullptr)
	{
	}

	ObjBase(float posX_, float posY_, ObjGroup group_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(group_),
		//colType(Collider_Non)
		colType(nullptr)
	{
	}

	ObjBase(float posX_, float posY_, std::string keyword_, ObjGroup group_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(keyword_),
		group(group_),
		//colType(Collider_Non)
		colType(nullptr)
	{
	}
	virtual ~ObjBase() 
	{
		delete colType;
	}

	//オブジェクト更新用
	virtual void Update() = 0;
	//オブジェクト描画用
	virtual void Draw() = 0;

	float GetPosX() { return posX; }
	float GetPosY() { return posY; }

	//usingFlags取得用
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag変更用
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

	virtual void OnCollision(ObjBase* obj_) = 0;

	//ColliderType GetColType() { return colType; }
	Collider* GetCollider() { return colType; }const

	ObjGroup GetObjGroup() { return group; }
protected:
	float posX;
	float posY;
	bool usingFlag;		//使えるかどうか
	//オブジェクトの名前
	std::string textureKeyword;
	ObjGroup group;
	Collider* colType;
	//ColliderType colType;
};