#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
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
				_getch();

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

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 

	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}