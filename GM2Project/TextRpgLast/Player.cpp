#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	UObject* ObjectPtr = this; //업캐스팅
	UStatusUnit* StatusUnitPtr = this;
	UFightUnit* FightUnitPtr = this;
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();
}

int APlayer::GetDamage() const
{
	return UFightUnit::GetDamage() + EquipAtt;
}


void APlayer::StatusTextRender()
{
	printf_s("공격력 : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("체력 : %d\n", Hp);
	printf_s("골드 : %d\n", Gold);
}
