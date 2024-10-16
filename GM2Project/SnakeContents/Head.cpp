#include "Head.h"

// std
#include <conio.h>

// 엔진 
#include <EngineBase/EngineMath.h>
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

// 컨텐츠
#include "Body.h"


void Head::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	FIntPoint Size = ConsoleEngine::GetEngine().GetWindow()->GetBackBufferPtr()->GetImageSize();
	FIntPoint CenterPos = Size / 2;

	SetActorLocation(CenterPos);

}

void Head::Move()
{
	PrevPos = GetActorLocation();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			TraceMove();
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			TraceMove();
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			TraceMove();
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			TraceMove();
			break;
		default:
			break;
		}
	}


}

// 함수 하나에서 철저하게 집중하면 된다.
void Head::EatCheck()
{
	FIntPoint BodyPos = Body::CurEatBody->GetActorLocation();
	FIntPoint ThisPos = GetActorLocation();

	if (BodyPos == ThisPos)
	{
		push_back(Body::CurEatBody);

		ListNode* LastNode = this->GetLastNode();
		ListNode* PrevNode = LastNode->Prev;

		FIntPoint CurPos = PrevNode->GetPrevPos();

		LastNode->SetActorLocation(PrevNode->GetPrevPos());

	}

	// body를 하나더 만들어야 한다.,
}

void Head::Tick()
{
	Super::Tick();
	// 철저하게 이동한다라는 행동만 한다.
	Move();
	EatCheck();
}

