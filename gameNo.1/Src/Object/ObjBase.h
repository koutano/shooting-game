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

//オブジェクト基底クラス
class ObjBase
{
public:
	//コンストラクタ
	//引数　float型座標 X,Y
	ObjBase(float posX_,float posY_) :
		posX(posX_),
		posY(posY_),
		usingFlag(true),
		textureKeyword(""),
		group(Group_Non),
		col()
	{
	}

	//コンストラクタ
	//第1引数  float型座標
	//第2引数　オブジェクトの名前
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

	//オブジェクト更新用
	virtual void Update() = 0;
	//オブジェクト描画用
	virtual void Draw() = 0;
	//usingFlags取得用
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag変更用
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

	virtual void OnCollision(ObjBase* obj_) = 0;

	Collider* GetCollider() { return col; }

	ObjGroup GetObjGroup() { return group; }
protected:
	float posX;
	float posY;
	bool usingFlag;		//使えるかどうか
	//オブジェクトの名前
	std::string textureKeyword;		
	ObjGroup group;
	Collider* col;
};