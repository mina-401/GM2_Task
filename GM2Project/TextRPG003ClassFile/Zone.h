#pragma once
#include "StatusUnit.h"


// 귀찮음이 있으면 큰일 납니다.
class UZone : public UObject
{
public:
	void InMsgPrint();
	bool IsConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool InterConnecting(UZone* _LinkZone);

private:
	UZone* LinkZone[5] = {nullptr,}; //정적 바인딩
};