#pragma once
#include "ConsoleImage.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진
class Player
{
public:
	void BeginPlay();
	void Tick(ConsoleImage* _BackBuffer);
	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void CheckPos(FIntPoint& _Pos);
	void CheckPos2(FIntPoint& _Pos);
	void SetBackBuffer(ConsoleImage* _BackBuffer)
	{
		BackBuffer = _BackBuffer;
	}

	void SetPos(FIntPoint& _Pos)
	{
		Pos = _Pos;
	}

	FIntPoint GetPos()
	{
		return Pos;
	}

private:
	FIntPoint Pos;
	ConsoleImage PlayerImage;

	ConsoleImage* BackBuffer;

};
