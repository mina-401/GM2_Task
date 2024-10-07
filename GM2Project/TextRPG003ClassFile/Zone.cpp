#include "Zone.h"
#include <conio.h>
#include "ContentsConst.h"
#include "BaseSystem/EngineDebug.h"

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
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
	//연결전에 이미 이지역과 연결되어있는가?
	if(this == _LinkZone) {
		MSGASSERT("같은 지역을 연결하고 있습니다."); return false;
	}
	if (IsConnecting(_LinkZone)) {
		MSGASSERT("이미 연결된 지역을 같은 지역에 또 연결하려고 했습니다."); return false;
	}
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr == LinkZone[i]) {
			LinkZone[i] = _LinkZone;
			return true;

		}
	}

	{
		MSGASSERT("이미 모든 연결이 완결된 지역이라 연결에 실패했습니다."); return false;
	}
}

bool UZone::InterConnecting(UZone* _LinkZone)
{
	
	this->Connecting(_LinkZone);
	_LinkZone->Connecting(this);
	return true;
	
}
