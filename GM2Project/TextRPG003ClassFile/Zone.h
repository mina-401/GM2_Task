#pragma once
#include "StatusUnit.h"


// �������� ������ ū�� ���ϴ�.
class UZone : public UObject
{
public:
	void InMsgPrint();
	bool IsConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool InterConnecting(UZone* _LinkZone);

private:
	UZone* LinkZone[5] = {nullptr,}; //���� ���ε�
};