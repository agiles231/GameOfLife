#include <iostream>
#include "GameOfLifeBuilder.h"


namespace GameOfLife {

	GameOfLifeBuilder::GameOfLifeBuilder(int xSize, int ySize)
	{
		this->xSize = xSize;
		this->ySize = ySize;
		cells = new bool*[xSize];
		for (int i = 0; i < xSize; i++) {
			cells[i] = new bool[ySize];
			for (int j = 0; j < ySize; j++) {
				cells[i][j] = false;
			}
		}
	}


	GameOfLifeBuilder::~GameOfLifeBuilder()
	{
		for (int i = 0; i < xSize; i++) {
			delete[] cells[i];
		}
		delete[] cells;
	}

	bool GameOfLifeBuilder::getCellAlive(int x, int y) {
		bool error = false;
		if (x > xSize) {
			std::cout << "setCell failed: x is greater than xSize (" << x << " > " << xSize << ")" << std::endl;
			error = true;
		}
		if (y > ySize) {
			std::cout << "setCell failed: y is greater than ySize (" << y << " > " << ySize << ")" << std::endl;
			error = true;
		}
		if (error) {
			return false;
		} else {
			return cells[x][y];
		}
	}

	void GameOfLifeBuilder::setCellAlive(int x, int y, bool alive) {
		bool error = false;
		if (x > xSize) {
			std::cout << "setCell failed: x is greater than xSize (" << x << " > " << xSize << ")" << std::endl;
			error = true;
		}
		if (y > ySize) {
			std::cout << "setCell failed: y is greater than ySize (" << y << " > " << ySize << ")" << std::endl;
			error = true;
		}
		if (error) {
			return;
		}
		else {
			cells[x][y] = alive;
		}
	}

	GameOfLifeInstance* GameOfLifeBuilder::build() {
		GameOfLifeInstance* gameOfLife = new GameOfLifeInstance(xSize, ySize, cells);
		cells = new bool*[xSize];
		for (int i = 0; i < xSize; i++) {
			cells[i] = new bool[ySize];
			for (int j = 0; j < ySize; j++) {
				cells[i][j] = false;
			}
		}
		return gameOfLife;
	}
}
