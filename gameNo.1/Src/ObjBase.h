#pragma once
#include<string>
#include"Mathematics.h"
//�I�u�W�F�N�g���N���X
class ObjBase
{
public:
	//�R���X�g���N�^
	//�����@Vecter2�^���W
	ObjBase(Vector2 pos_) :
		pos(pos_),
		usingFlag(true),
		textureKeyword("")
	{
	}

	//�R���X�g���N�^
	//��1�����@Vecter2�^���W
	//��2�����@�I�u�W�F�N�g�̖��O
	ObjBase(Vector2 pos_, std::string keyword) :
		pos(pos_),
		usingFlag(true),
		textureKeyword(keyword)
	{
	}
	//�I�u�W�F�N�g�X�V�p
	virtual void Update() = 0;
	//�I�u�W�F�N�g�`��p
	virtual void Draw() = 0;
	//usingFlags�擾�p
	bool GetUsingFlag() { return usingFlag; }
	//usingFlag�ύX�p
	void SetUsingFlag(bool using_flag) { usingFlag = using_flag; }

protected:
	Vector2 pos;
	bool usingFlag;		//�g���邩�ǂ���
	//�I�u�W�F�N�g�̖��O
	std::string textureKeyword;		
};