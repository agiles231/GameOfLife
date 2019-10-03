#pragma once
#include "GameOfLifeInstance.h"

namespace GameOfLife {
	class RandomGameOfLifeGenerator
	{
	public:
		RandomGameOfLifeGenerator();
		~RandomGameOfLifeGenerator();

		GameOfLifeInstance generateRandomGameOfLife(int xSize, int ySize);
	};

}
