#include "RandomGameOfLifeGenerator.h"
#include "GameOfLifeBuilder.h"
#include "math.h"


namespace GameOfLife {

	RandomGameOfLifeGenerator::RandomGameOfLifeGenerator()
	{
	}


	RandomGameOfLifeGenerator::~RandomGameOfLifeGenerator()
	{
	}

	GameOfLifeInstance RandomGameOfLifeGenerator::generateRandomGameOfLife(int xSize, int ySize) {
		GameOfLifeBuilder builder = GameOfLifeBuilder(xSize, ySize);
		for (int i = 0; i < xSize; i++) {
			for (int j = 0; j < ySize; j++) {
				double r =  ((double)rand() / (double)RAND_MAX);
				builder.setCellAlive(i, j, (r >= 0.5));
			}
		}
		return *builder.build();
	}
}
