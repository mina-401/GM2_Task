#include "Town.h"
#include <conio.h>
#include "Player.h"

// �����ͳ� ���۷����� ������ 8����Ʈ �̱� ������
void UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������̵�\n";
		std::cout << "3. �߱޸����� �̵�\n";
		int Select = _getch();

		switch (Select)
		{
		case '2':
			_Player.SetCurrLocation(2);
			printf_s("2�������ϴ�.\n");
			_getch();
			return;
		case '3':
			_Player.SetCurrLocation(3);
			printf_s("3�������ϴ�.\n");
			_getch();
			return;
		case '0':
		case '1':
		
			break;
		default:
			break;
		}

	}
}
