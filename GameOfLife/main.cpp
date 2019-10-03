
#include "GameOfLifeInstance.h"
#include "RandomGameOfLifeGenerator.h"
#include "GameOfLifeSVGWriter.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace GameOfLife;
int main() {
	int xSize = 0;
	int ySize = 0;
	int numberOfIterations = 0;
	std::cout << "Grid size" << std::endl;
	std::cout << "Enter x size: ";
	std::cin >> xSize;
	std::cout << "Enter y size: ";
	std::cin >> ySize;
	std::cout << "Enter number of iterations (0 if interactive iterations is desired): ";
	std::cin >> numberOfIterations;
	RandomGameOfLifeGenerator randomGenerator = RandomGameOfLifeGenerator();
	GameOfLifeInstance gameOfLife = randomGenerator.generateRandomGameOfLife(xSize, ySize);
	for (int i = 0; i < numberOfIterations; i++) {
		gameOfLife.tick();
	}

	GameOfLifeWriter* writer;
	if (numberOfIterations > 0) {
		std::ofstream file;
		file.open("C:\\Users\\agile\\Desktop\\gameOfLife.svg");
		writer = new GameOfLifeSvgWriter(&file);
		writer->write(gameOfLife);
		file.close();
	}
	else {
		numberOfIterations = 0;
		std::string action = "";
		writer = new GameOfLifeWriter(&std::cout);
		writer->write(gameOfLife);
		while (action != "stop") {
			std::cin >> action;
			if (action == "tick") {
				gameOfLife.tick();
				writer->write(gameOfLife);
				numberOfIterations++;
			}
		}
	}
	return 0;
}