#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>
#include <conio.h>

void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	// C:\\

	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "이름을 적어주세요" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
		printf_s("a. 결정\n");
		printf_s("b. 재입력\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("잘못된 선택입니다. 다시 선택해주세요\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// 파일 저장

	_Player.SetName(InputName);
}

void UWorld::ZoneInit()
{
	// 지역들을 준비시키것.
	// 이니셜라이즈 단계
	// 객체들을 만들고 처음으로 준비시키는 단계
	// 대부분 딱 1번한다.
	TownZone0.SetName("초보마을");
	TownZone1.SetName("중급마을");
	FightZone.SetName("초보사냥터");

	//TownZone0.Connecting(&TownZone0);

	TownZone0.InterConnecting(&FightZone);

}


void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	//맵 준비, 플레이어도 다 된
//	_Player.SetCurZone(0);
//	_Player.SetGold(10000000);

	UZone* CurZone = &TownZone0;
	while (true)
	{
		CurZone = CurZone->InPlayer(_Player);
	}

}

//
void UWorld::PlayerInit(UPlayer& _Player)
{
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// 파일이 없을때
	if (false == File.IsExits())
	{
		File.FileOpen("wb");

		PlayerNameSelect(_Player);
		const char* Name = _Player.GetName();
		File.Write(Name, NAMELEN);
	}
	else
	{
		File.FileOpen("rb");

		char Arr[100] = {};
		File.Read(Arr, NAMELEN);
		_Player.SetName(Arr);
	}
}

void UWorld::InPlayer(class UPlayer& _Player)
{
	
	PlayerInit(_Player);

	//맵 준비
	ZoneInit();
	PlayerZonePlay(_Player);


	//return nullptr;
	//return this;
}