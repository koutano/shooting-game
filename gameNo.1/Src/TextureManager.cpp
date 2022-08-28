 #include <DxLib.h>
#include "TextureManager.h"

bool TextureManager::Load(std::string keyword, std::string file_name)
{
	if (handles.count(keyword) > 0)
	{
		return true;
	}

	int handle = LoadGraph(file_name.c_str());
	if (handle < 0)
	{
		return false;
	}
	handles[keyword] = handle;

	return true;
}

int TextureManager::GetHandle(std::string keyword)
{
	if (handles.count(keyword) > 0)
	{
		return handles[keyword];
	}

	return -1;
}

void TextureManager::AllDelete()
{
	InitGraph();
	handles.clear();
}

void TextureManager::Delete(std::string keyword)
{
	if (handles.count(keyword) > 0)
	{
		DeleteGraph(handles[keyword]);
		handles.erase(keyword);
	}
}
