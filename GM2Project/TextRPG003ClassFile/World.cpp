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
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
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
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// ���� ����

	_Player.SetName(InputName);
}

void UWorld::ZoneInit()
{
	// �������� �غ��Ű��.
	// �̴ϼȶ����� �ܰ�
	// ��ü���� ����� ó������ �غ��Ű�� �ܰ�
	// ��κ� �� 1���Ѵ�.
	TownZone0.SetName("�ʺ�����");
	TownZone1.SetName("�߱޸���");
	FightZone.SetName("�ʺ������");

	//TownZone0.Connecting(&TownZone0);

	TownZone0.InterConnecting(&FightZone);

}


void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	//�� �غ�, �÷��̾ �� ��
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

	// ������ ������
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

	//�� �غ�
	ZoneInit();
	PlayerZonePlay(_Player);


	//return nullptr;
	//return this;
}