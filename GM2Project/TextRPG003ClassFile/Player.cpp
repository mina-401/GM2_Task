#include "Player.h"


//멤버함수 분할 구현
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
