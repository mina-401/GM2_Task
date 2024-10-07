#pragma once
#include "ContentsConst.h"
#include "Object.h"

class UStatusUnit : public UObject
{
public:
	void StatusRender();
	void TopLine();
	void BotLine();

	void SetHp(int _Value)
	{
		Hp = _Value;
	}
	void SetMinAtt(int _Value)
	{
		MinAtt = _Value;
	}
	void SetMaxAtt(int _Value)
	{
		MaxAtt = _Value;
	}
	void SetSpeed(int _Value)
	{
		Speed = _Value;
	}
	void SetGold(int _Value)
	{
		Gold = _Value;
	}

	int GetHp() 
	{
		return Hp;
	}
	int GetMinAtt() 
	{ 
		return MinAtt; 
	}
	int GetMaxAtt() 
	{ 
		return MaxAtt; 
	}
	int GetSpeed() 
	{ 
		return Speed; 
	}
	int GetGold() 
	{ 
		return Gold; 
	}

	int GetEnforce()
	{
		return Enforce;
	}
	void SetEnforce(int _enforce)
	{
		Enforce = Enforce + _enforce;
	}
protected:
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 10;
	int Gold = 0;
	int Enforce = 0;

	virtual void StatusTextPrint() {};


private:
};
