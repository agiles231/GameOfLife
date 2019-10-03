#pragma once
#include "GameOfLifeInstance.h"
#include <iostream>
#include <ostream>

namespace GameOfLife {
	class GameOfLifeWriter
	{
	protected:
		std::ostream* o;
	public:
		GameOfLifeWriter() { this->o = &std::cout; };
		GameOfLifeWriter(std::ostream* o) { this->o = o; };
		virtual ~GameOfLifeWriter() {};

		virtual void write(GameOfLifeInstance& gameOfLife) {
			int xSize = gameOfLife.getXSize();
			int ySize = gameOfLife.getYSize();
			(*o) << "-";
			for (int i = 0; i < xSize; i++) {
				(*o) << " - ";
			}
			(*o) << "-";
			(*o) << std::endl;
			for (int j = 0; j < ySize; j++) {
				(*o) << "|";
				for (int i = 0; i < xSize; i++) {
					if (gameOfLife.getCellAlive(i, j)) {
						(*o) << " X ";
					} else {
						(*o) << "   ";
					}
				}
				(*o) << "|";
				(*o) << std::endl;
			}
			(*o) << "-";
			for (int i = 0; i < xSize; i++) {
				(*o) << " - ";
			}
			(*o) << "-";
			(*o) << std::endl;
		};
	};

}