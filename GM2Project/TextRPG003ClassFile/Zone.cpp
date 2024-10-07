#include "Zone.h"
#include <conio.h>
#include "ContentsConst.h"
#include "BaseSystem/EngineDebug.h"

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "�� �����߽��ϴ�.\n";
}

bool UZone::IsConnecting(UZone* _LinkZone)
{
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (_LinkZone == LinkZone[i])
		{
			return true;
		}
	}

	return false;
}
bool UZone::Connecting(UZone* _LinkZone)
{
	//�������� �̹� �������� ����Ǿ��ִ°�?
	if(this == _LinkZone) {
		MSGASSERT("���� ������ �����ϰ� �ֽ��ϴ�."); return false;
	}
	if (IsConnecting(_LinkZone)) {
		MSGASSERT("�̹� ����� ������ ���� ������ �� �����Ϸ��� �߽��ϴ�."); return false;
	}
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr == LinkZone[i]) {
			LinkZone[i] = _LinkZone;
			return true;

		}
	}

	{
		MSGASSERT("�̹� ��� ������ �ϰ�� �����̶� ���ῡ �����߽��ϴ�."); return false;
	}
}

bool UZone::InterConnecting(UZone* _LinkZone)
{
	
	this->Connecting(_LinkZone);
	_LinkZone->Connecting(this);
	return true;
	
}
