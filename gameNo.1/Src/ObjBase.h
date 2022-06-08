#pragma once
#include<string>
#include"Mathematics.h"
//オブジェクト基底クラス
class ObjBase
{
public:
	//コンストラクタ
	//引数　Vecter2型座標
	ObjBase(Vector2 pos_) :
		pos(pos_),
		usingFlag(true),
		textureKeyword("")
	{
	}

	//コンストラクタ
	//第1引数　Vecter2型座標
	//第2引数　オブジェクトの名前
	ObjBase(Vector2 pos_, std::string keyword) :
		pos(pos_),
		usingFlag(true),
		textureKeyword(keyword)
	{
	}
	//オブジェクト更新用
	virtual void Update() = 0;
	//オブジェクト描画用
	virtual void Draw() = 0;
	//usingFlags取得用
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag変更用
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

protected:
	Vector2 pos;
	bool usingFlag;		//使えるかどうか
	//オブジェクトの名前
	std::string textureKeyword;		
};