#include "Cover.h"
#include <EngineCore/Renderer.h>

void Cover::BeginPlay()
{
	Super::BeginPlay();

	Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, '#');

	//
}

void Cover::SetPixel(class FIntPoint pos)
{
	Render->RenderImage.SetPixel({ pos.X, pos.Y }, '@');
}
