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

		std::cout << "�̸��� �����ּ���" << std::endl;
		std::cin >> InputName;
		bool IsFinalEnd = false;
		while (true)
		{
			printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
			printf_s("a. ����\n");
			printf_s("b. ���Է�\n");
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
				printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
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

void UWorld::PlayerZonePlay(UPlayer& _Player)
{
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	UTown TownZone1;
	TownZone1.SetName("�߱޸���"); //3

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������"); //2


	int nextZone = TownZone.InPlayer(_Player);
	while (nextZone)
	{
		// 
		switch (nextZone)
		{
		case 1:
			break;
		case 2:
			nextZone = FightZone.InPlayer(_Player);
			break;
		case 3:
			nextZone = TownZone1.InPlayer(_Player);
			break;
		default:
			break;
		}
		
		
		

		//if(nextZone)
	}
}

void UWorld::InPlayer(class UPlayer& _Player)
{
	
	//������ ������ ���� ����

	/*if (true) {
		PlayerNameSelect(_Player);
	}
	else {

	}*/

	//������ ���̸����� ����

	_Player.SetName("TestPlayer");
	
	
	PlayerZonePlay(_Player);


}

