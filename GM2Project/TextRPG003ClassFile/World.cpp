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
void UWorld::ZoneInit()
{
	TownZone0.SetName("�ʺ�����"); 
	TownZone1.SetName("�߱޸���"); 
	FightZone.SetName("�ʺ������");

	//UZone upcasting
	TownZone0.InterConnecting(&FightZone); //Townzone�� 0�� == FightZone�� 0��
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
			//����� �����Ѵ�
			FightZone.InPlayer(_Player);
			break;
		case 3:
			//�߱޸��� �̵��Ѵ�.
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

