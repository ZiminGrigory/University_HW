#pragma once
namespace Epsilon {
	int const LINUX = 5;
	int const WINDOWS = 20;
	int const MAC_OS = 15;
}

enum OS {
	LINUX,
	WINDOWS,
	MAC_OS
};

int const DATA_KEY = 25;

namespace MaxRiskOfResist{
	int const LINUX = 90;
	int const WINDOWS = 50;
	int const MAC_OS = 60;
}

namespace RecoverySystemChance{
	int const LINUX = 90;
	int const WINDOWS = 60;
	int const MAC_OS = 60;
}

int const numberOfPC = 8;
int const VIRUS_CHANCE = 50;

enum AttackStatus{
	INFECTED,
	NOT_INFECTED
};
