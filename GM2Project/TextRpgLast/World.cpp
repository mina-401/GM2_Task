#include "World.h"

void UWorld::ZoneInit()
{
	Town0.SetName("�ʺ�����");
	Town1.SetName("�߱޸���");
	FZone0.SetName("�ʺ������");
}

void UWorld::PlayerZonePlay()
{
	UZone* CurZone = &Town0;

	while (true)
	{
		// �����ʹ� ��ü�� �ƴϰ�
		// �׳� �ּҰ��� ���̴�. �������� ����ɼ� �ִ�.
		// UZone������ �ڽ��� �Լ����� ����˴ϴ�.
		CurZone = CurZone->InPlayer();
	}
}
