#include "TextRpgCore.h"
#include "Player.h"
#include "World.h"

// 플레이어는 딱 1명이다.
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