#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>
#include <conio.h>

//void UWorld::PlayerNameSelect()
//{
//	// C:\\
//
//	char InputName[100] = { 0, };
//
//	bool IsNameInput = true;
//
//	while (true)
//	{
//		if (true == IsNameInput)
//		{
//			system("cls");
//			std::cout << "이름을 적어주세요" << std::endl;
//			std::cin >> InputName;
//		}
//
//		system("cls");
//		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
//		printf_s("a. 결정\n");
//		printf_s("b. 재입력\n");
//		int Select = _getch();
//
//		bool IsEnd = true;
//		switch (Select)
//		{
//		case 'a':
//		case 'A':
//			IsEnd = true;
//			break;
//		case 'b':
//		case 'B':
//			IsEnd = false;
//			IsNameInput = true;
//			break;
//		default:
//			IsEnd = false;
//			IsNameInput = false;
//			printf_s("잘못된 선택입니다. 다시 선택해주세요\n");
//			_getch();
//			break;
//		}
//
//		if (true == IsEnd)
//		{
//			break;
//		}
//	}
//
//	// 파일 저장
//
//	_Player.SetName(InputName);
//}

void UWorld::ZoneInit()
{
	Town0.SetName("초보마을");
	Town1.SetName("중급마을");

	FZone0.SetName("초보사냥터");
	FZone0.SetMonsterType(Enums::MONSTERTYPE::GOBLIN);

	Town0.InterConnecting(FZone0);

}


void UWorld::PlayerZonePlay()
{

	UZone* CurZone = &TownZone0;
	while (true)
	{
		CurZone = CurZone->InPlayer();
	}

}

//
//void UWorld::PlayerInit()
//{
//	UEngineFile File;
//	File.SetPath("SaveFile.Dat");
//
//	// 파일이 없을때
//	if (false == File.IsExits())
//	{
//		File.FileOpen("wb");
//
//		PlayerNameSelect(_Player);
//		const char* Name = _Player.GetName();
//		File.Write(Name, NAMELEN);
//	}
//	else
//	{
//		File.FileOpen("rb");
//
//		char Arr[100] = {};
//		File.Read(Arr, NAMELEN);
//		_Player.SetName(Arr);
//	}
//}

void UWorld::InPlayer()
{

	ZoneInit();
	PlayerZonePlay();

}