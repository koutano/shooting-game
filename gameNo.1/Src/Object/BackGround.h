#pragma once
#include"ObjBase.h"
//�w�i�N���X
class BackGround :public ObjBase
{
public:
	/*
	�R���X�g���N�^
	*/
	BackGround() :
		ObjBase(0, 0, "BackGround")
	{

	}
	//�f�X�g���N�^
	~BackGround()override { delete colType; }
	//�X�V�p
	void Update()override;
	//�`��p
	void Draw()override;
	//�����莞����
	//�w�i�Ȃ̂ŉ������Ȃ�
	void OnCollision(ObjBase* obj_)override;

private:

};