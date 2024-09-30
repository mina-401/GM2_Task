#pragma once
#include "EngineConst.h"
#include "EngineDebug.h"
#include <iostream>

class UObject
{
public:
	void SetName(const char* const _Name);
	inline const char* GetName()
	{
		return Name;
	}

	// 부모자식간에서
	// 지킬건 부모 사생활을 
//protected:
//	char Name[NAMELEN] = "NONE";
	// UPlayer* Player;

private:
	char Name[NAMELEN] = "NONE";
};