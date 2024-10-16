#pragma once
#include <EngineCore/Actor.h>

class Cover : public AActor
{
public:
	void BeginPlay() override;
	void SetPixel(class FIntPoint pos);

	class Renderer* Render;
};
