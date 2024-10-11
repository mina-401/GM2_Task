#pragma once
#include "Town.h"
#include "FightZone.h"

class UWorld
{
public:
	//void PlayerInit();
	void InPlayer();

private:
	void ZoneInit();
	//void PlayerNameSelect(class UPlayer& _Player);
	void PlayerZonePlay();

	UTown TownZone0;
	UTown TownZone1;
	UFightZone FightZone;
};

