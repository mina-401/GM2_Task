#include "Block.h"
#include <EngineCore/Renderer.h>
#include <conio.h>
#include "Cover.h"

//Cover* Cover::CoverPtr = nullptr;
void Block::BeginPlay()
{
	Super::BeginPlay();

	Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
	//Cover* cover = Cover::GetCoverPtr();

}

void Block::Tick()
{
	Super::Tick();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}

	}

	FIntPoint pos = CoverPtr->Render->RenderImage.GetPixel('@');
	//화면보다 아래로 내려감
	if (GetActorLocation().Y >= 4)
	{
		CoverPtr->SetPixel(GetActorLocation());
		// CoverPtr->Render->RenderImage.GetPixel(@)

		SetActorLocation({ 0,0 });

	}
	//아래에 @이가 있다.
	if (GetActorLocation().Y == pos.Y-1 && GetActorLocation().X==pos.X )
	{
		CoverPtr->SetPixel(GetActorLocation());
		//CoverPtr->Render->RenderImage.GetPixel(@)

		SetActorLocation({ 0,0 });
	}
	

	//if(CoverPtr->Render->RenderImage.Get

	// CoverPtr->Render->RenderImage.GetPixel(@)
	// 2가지

	//바닥에 닿으면 cover의 pixel위치에 @를 그린다.


}