#include "Player.h"


//����Լ� ���� ����
UPlayer::UPlayer()
{

}
void UPlayer::Equip(class Item* Weapon)
{

}

void UPlayer::SetCurrLocation(int _currentLocationIndex)
{
	currentLocationIndex = _currentLocationIndex;
}
int UPlayer::GetCurrLocation() {
	return currentLocationIndex;
}
