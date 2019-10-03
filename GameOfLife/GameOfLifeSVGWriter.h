#pragma once
#include "GameOfLifeInstance.h"
#include "GameOfLifeWriter.cpp"
#include <fstream>
#include <string>
namespace GameOfLife {
	class GameOfLifeSvgWriter : public GameOfLifeWriter
	{
	private:
		float version;
		int squareSize;
		std::string fill;
		std::string deadFill ;
		std::string aliveFill ;
		int strokeWidth;
		std::string stroke;
	public:
		GameOfLifeSvgWriter(std::ofstream* const outfile, int squareSize, std::string aliveFill, std::string deadFill, int strokeWidth, std::string stroke, float version = 1.1f);
		GameOfLifeSvgWriter(std::ofstream* const outfile, float version = 1.1f);
		~GameOfLifeSvgWriter();

		void write(GameOfLifeInstance& gameOfLife, int squareSize);
		void write(GameOfLifeInstance& gameOfLife);
	};

}
