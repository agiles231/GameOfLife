#pragma once
#include <vector>
#include "GameOfLifeInstance.h"

namespace GameOfLife {
	class GameOfLifeBuilder
	{
	private:
		int xSize;
		int ySize;
		bool** cells;
	public:
		GameOfLifeBuilder(int xSize, int ySize);
		~GameOfLifeBuilder();

		int getXSize() { return xSize; }
		int getYSize() { return ySize; }
		bool** getCells() { return cells; }

		bool getCellAlive(int x, int y);

		void setCellAlive(int x, int y, bool alive);

		GameOfLifeInstance* build();
	};

}
