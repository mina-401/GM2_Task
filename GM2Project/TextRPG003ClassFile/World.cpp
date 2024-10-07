#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <conio.h>

void UWorld::PlayerNameSelect(UPlayer& _Player)
{
	char InputName[100] = { 0, };

	while (true)
	{
		system("cls");

		std::cout << "이름을 적어주세요" << std::endl;
		std::cin >> InputName;
		bool IsFinalEnd = false;
		while (true)
		{
			printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
			printf_s("a. 결정\n");
			printf_s("b. 재입력\n");
			int Select = _getch();
			bool IsEnd = false;
			switch (Select)
			{
			case 'a':
			case 'A':
				IsEnd = true;
				IsFinalEnd = true;
				break;
			case 'b':
			case 'B':
				IsEnd = true;
				IsFinalEnd = false;
				break;
			default:
				printf_s("잘못된 선택입니다. 다시 선택해주세요\n");
				int ch = _getch();
				system("cls");

				break;
			}if (true == IsEnd)
			{
				break;
			}
		}


		if (true == IsFinalEnd)
		{
			break;
		}
	}
	_Player.SetName(InputName);
}
void UWorld::ZoneInit()
{
	TownZone0.SetName("초보마을"); 
	TownZone1.SetName("중급마을"); 
	FightZone.SetName("초보사냥터");

	//UZone upcasting
	TownZone0.InterConnecting(&FightZone); //Townzone의 0번 == FightZone의 0번
	//TownZone0.InterConnecting(&FightZone);

	int a = 0;
	//TownZone0.InterConnecting(&FightZone);
}

void UWorld::PlayerZonePlay(UPlayer& _Player)
{

	ZoneInit();



	//player location
	_Player.SetCurrLocation(1);
	int currLocation = 1;
	while (currLocation)
	{
		// 
		currLocation = _Player.GetCurrLocation();
		switch (currLocation)
		{
		case 1:
			TownZone0.InPlayer(_Player);
			break;
		case 2:
			//사냥터 입장한다
			FightZone.InPlayer(_Player);
			break;
		case 3:
			//중급마을 이동한다.
			TownZone1.InPlayer(_Player);
			break;
		default:
			break;
		}

		//if(nextZone)
	}
}


void UWorld::InPlayer(class UPlayer& _Player)
{
	
	//파일이 없으면 네임 셀렉

	/*if (true) {
		PlayerNameSelect(_Player);
	}
	else {

	}*/

	//없으면 그이름으로 시작

	_Player.SetName("TestPlayer");
	
	
	PlayerZonePlay(_Player);


}

