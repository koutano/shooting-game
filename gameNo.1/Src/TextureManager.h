#pragma once
#include <map>
#include <string>

//�摜�`��⏕�p�N���X
class TextureManager
{
public:
	//�V���O���g��
	static TextureManager* Instance()
	{
		static TextureManager instance;
		return &instance;
	}
	/*
	�摜���[�h�p�֐�
	����
	1:string�^�L�[���[�h
	2:string�^�t�@�C���̖��O
	�߂�l
	true:�ǂݍ��ݐ���
	false:�ǂݍ��ݎ��s
	*/
	bool Load(std::string keyword, std::string file_name);
	/*
	�摜�n���h���擾�p�֐�
	����
	1:string�^�L�[���[�h
	�߂�l
	�摜�̃n���h��
	*/
	int GetHandle(std::string keyword);
	/*
	�摜����p�֐�
	*/
	void AllDelete();
	/*
	�����̉摜����p�֐�
	����
	1:string�^�L�[���[�h
	*/
	void Delete(std::string);

private:
	TextureManager()
	{}
	//TextureManager�����p
	TextureManager(TextureManager* instance) = delete;

private:
	//�摜�i�[�p
	std::map<std::string, int> handles;
};

