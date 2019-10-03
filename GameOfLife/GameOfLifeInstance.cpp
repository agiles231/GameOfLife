#include <iostream>
#include "GameOfLifeInstance.h"
#include "GameOfLifeBuilder.h"


namespace GameOfLife {

	void GameOfLifeInstance::setCellAliveNextTick(int x, int y, bool alive) {
		swapCells[x][y] = alive;
	}


	int GameOfLifeInstance::countNeighborsAlive(int x, int y) {
		int xm = (x + xSize - 1) % xSize;
		int xp = (x + 1) % xSize;
		int ym = (y + ySize - 1) % ySize;
		int yp = (y + 1) % ySize;
		int aliveCount = 0;
		aliveCount += getCellAlive(xm, ym) ? 1 : 0;
		aliveCount += getCellAlive(x, ym) ? 1 : 0;
		aliveCount += getCellAlive(xp, ym) ? 1 : 0;
		aliveCount += getCellAlive(xp, y) ? 1 : 0;
		aliveCount += getCellAlive(xp, yp) ? 1 : 0;
		aliveCount += getCellAlive(x, yp) ? 1 : 0;
		aliveCount += getCellAlive(xm, yp) ? 1 : 0;
		aliveCount += getCellAlive(xm, y) ? 1 : 0;
		return aliveCount;
	}
	GameOfLifeInstance::GameOfLifeInstance(int xSize, int ySize, bool** cells)
	{
		this->xSize = xSize;
		this->ySize = ySize;
		this->cells = cells;
		swapCells = new bool*[xSize];
		for (int i = 0; i < xSize; i++) {
			swapCells[i] = new bool[ySize];
			for (int j = 0; j < ySize; j++) {
				swapCells[i][j] = cells[i][j];
			}
		}
	}


	GameOfLifeInstance::~GameOfLifeInstance()
	{
		for (int i = 0; i < xSize; i++) {
			delete[] cells[i];
			delete[] swapCells[i];
		}
		delete[] cells;
		delete[] swapCells;
	}

	void GameOfLifeInstance::tick() {
		for (int i = 0; i < xSize; i++) {
			for (int j = 0; j < ySize; j++) {
				int aliveCount = countNeighborsAlive(i, j);

				bool curCellAlive = getCellAlive(i, j);
				bool alive = false;
				if (curCellAlive) {
					if (aliveCount == 2 || aliveCount == 3)
						alive = true;
				}
				else if (aliveCount == 3) {
					alive = true;
				}
				setCellAliveNextTick(i, j, alive);
			}
		}
		swapBuffers();
	}

	bool GameOfLifeInstance::getCellAlive(int x, int y) {
		if (xSize > x && ySize > y) {
			return cells[x][y];
		}
		else {
			std::cout << "Exception occurred trying to get cell at position x: " << x << ", y: " << y;
			return false;
		}
	}
}
