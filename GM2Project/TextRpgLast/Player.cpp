#include "Player.h"
#include <iostream>

UPlayer::UPlayer()
{
	UObject* ObjectPtr = this;
	UStatusUnit* StatusUnitPtr = this;
	UFightUnit* FightUnitPtr = this;
}

void UPlayer::StatusTextRender()
{
	printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("ü�� : %d\n", Hp);
	printf_s("��� : %d\n", Gold);
}
