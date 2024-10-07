#pragma once
#include "FightUnit.h"
//#include "Item.h"

class Item; //���漱��, �ߺ��ص��ǰ�, �Ʒ����� �ٽ� ����� ���ÿ� �ص� �ȴ�.
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

	//�����ʹ� ������ 8 ����Ʈ �̱� ������ ����� ���� �ȴ�.
	//����Ť� ��� ������ Item�� ����߱� ������ �˰��־���Ѵ�. 
	// ���漱�� extern int a; ó�� class name* a;
	//class Item& �� �ȵȴ�. ref�� �ʱ�ȭ�� ������ �ʿ��ϴ�.
	class Item* Weapon =nullptr;

	//void Equip(Item* Weapon)
	//{
	//	//�Լ��� ������ cpp���� �ϴ� ���� header ��ȯ���� �������ؼ� �̴�.
	//	// header�� cpp���� �� cpp���� �������ϱ� ������ �����϶� �ð��� �����ɸ���.
	//	//Weapon->Test(); //�ش� Ŭ������ �Լ��� �� �� header�ʿ��ϴ�.
	//}
};
