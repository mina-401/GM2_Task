#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
	//static Cover* GetCoverPtr() 
	//{
	//	return CoverPtr;
	//}

	class Cover* CoverPtr;

private:
	//static class Cover* CoverPtr;
	class Renderer* Render;
};

