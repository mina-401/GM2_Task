#pragma once
#include "FightUnit.h"
//#include "Item.h"

class Item; //전방선언, 중복해도되고, 아래에서 다시 선언과 동시에 해도 된다.
//class Item* Weapon;

class UPlayer : public UFightUnit
{

public:
	UPlayer();
	void Equip(class Item* Weapon);
	void SetCurrLocation(int _currentLocationIndex);
	int GetCurrLocation();
private:
	int currentLocationIndex = 0;
public:

	//포인터는 무조건 8 바이트 이기 때문에 헤더를 몰라도 된다.
	//헤더거ㅏ 없어도 되지만 Item을 사용했기 때문에 알고있어야한다. 
	// 전방선언 extern int a; 처럼 class name* a;
	//class Item& 는 안된다. ref는 초기화가 무조건 필요하다.
	class Item* Weapon =nullptr;

	//void Equip(Item* Weapon)
	//{
	//	//함수의 구현을 cpp에서 하는 이유 header 순환참조 막기위해서 이다.
	//	// header는 cpp에서 각 cpp에서 컴파일하기 때문에 컴파일때 시간이 오래걸린다.
	//	//Weapon->Test(); //해당 클래스의 함수를 쓸 땐 header필요하다.
	//}
};
