#pragma once
#include <vector>
namespace GameOfLife {
	class GameOfLifeInstance
	{
	private:
		bool** cells;
		bool** swapCells;
		int xSize, ySize;

		void setCellAliveNextTick(int x, int y, bool alive);
		void swapBuffers() { bool** tmp = cells; cells = swapCells; swapCells = tmp; }
		int countNeighborsAlive(int x, int y);
	public:
		GameOfLifeInstance(int xSize, int ySize, bool** cells);
		~GameOfLifeInstance();

		void tick(); // advance the game by one tick

		int getXSize() { return xSize; }
		int getYSize() { return xSize; }
		bool getCellAlive(int x, int y);
	};

}
