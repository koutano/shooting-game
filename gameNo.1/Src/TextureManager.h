#pragma once
#include <map>
#include <string>

//画像描画補助用クラス
class TextureManager
{
public:
	//シングルトン
	static TextureManager* Instance()
	{
		static TextureManager instance;
		return &instance;
	}
	/*
	画像ロード用関数
	引数
	1:string型キーワード
	2:string型ファイルの名前
	戻り値
	true:読み込み成功
	false:読み込み失敗
	*/
	bool Load(std::string keyword, std::string file_name);
	/*
	画像ハンドル取得用関数
	引数
	1:string型キーワード
	戻り値
	画像のハンドル
	*/
	int GetHandle(std::string keyword);
	/*
	画像解放用関数
	*/
	void AllDelete();
	/*
	引数の画像解放用関数
	引数
	1:string型キーワード
	*/
	void Delete(std::string);

private:
	TextureManager()
	{}
	//TextureManager消去用
	TextureManager(TextureManager* instance) = delete;

private:
	//画像格納用
	std::map<std::string, int> handles;
};

