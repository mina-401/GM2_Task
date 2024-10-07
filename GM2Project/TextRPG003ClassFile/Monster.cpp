#include "Monster.h"


void UMonster::StatusRender()
{
	printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("체력 : %d\n", Hp);
}

