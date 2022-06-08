#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <map>
#include <string>

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		static TextureManager instance;
		return &instance;
	}

	bool Load(std::string keyword, std::string file_name);
	int GetHandle(std::string keyword);
	void AllDelete();
	void Delete(std::string);

private:
	TextureManager()
	{}

	TextureManager(TextureManager* instance) = delete;

private:
	std::map<std::string, int> handles;
};

#endif
