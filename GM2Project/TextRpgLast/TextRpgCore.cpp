#include "TextRpgCore.h"
#include "Player.h"
#include "World.h"

// �÷��̾�� �� 1���̴�.
UPlayer MainPlayer;
UWorld World;

UPlayer& TextRpgCore::GetPlayer()
{
	return MainPlayer;
}

TextRpgCore::TextRpgCore()
{

}

void TextRpgCore::Start()
{
	MainPlayer.SetName("MainPlayer");
	World.ZoneInit();
	World.PlayerZonePlay();
}