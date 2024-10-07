#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	// 안넣어주면 생성이 안되.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	void TryUpgrade(class UPlayer& _Player);
	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

private:
	// class UZone& ParentZone;

	class UZone* ParentZone = nullptr;
};

