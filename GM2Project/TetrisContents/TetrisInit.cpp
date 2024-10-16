#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "Cover.h"


void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// 시작을 합니다.
	_MainEngine->GetWindow()->SetScreenSize({ 3, 5 });
	Cover* CoverPtr= _MainEngine->SpawnActor<Cover>();
	Block* BlockPtr= _MainEngine->SpawnActor<Block>();
	BlockPtr->CoverPtr = CoverPtr;


}
