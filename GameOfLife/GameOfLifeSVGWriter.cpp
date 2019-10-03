#include "GameOfLifeSVGWriter.h"

namespace GameOfLife {

	GameOfLifeSvgWriter::GameOfLifeSvgWriter(std::ofstream* const outfile, int squareSize, std::string aliveFill, std::string deadFill, int strokeWidth, std::string stroke, float version) {
		this->o = outfile;
		this->squareSize = squareSize;
		this->deadFill = deadFill ;
		this->aliveFill = aliveFill ;
		this->strokeWidth = strokeWidth;
		this->stroke = stroke;
		this->version = version;
	}

	GameOfLifeSvgWriter::GameOfLifeSvgWriter(std::ofstream* const outfile, float version) : GameOfLifeSvgWriter(outfile, 25, "black", "white", 2, "red", version) {
	}

	GameOfLifeSvgWriter::~GameOfLifeSvgWriter()
	{
	}

	void GameOfLifeSvgWriter::write(GameOfLifeInstance& gameOfLife) {
		int totalWidth = squareSize + strokeWidth;
		(*o) << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << std::endl;
		(*o) << "<svg xmlns=\"" << "http://www.w3.org/2000/svg" << "\" version=\"" << version << "\">" << std::endl;
		for (int i = 0; i < gameOfLife.getXSize(); i++) {
			for (int j = 0; j < gameOfLife.getYSize(); j++) {
				(*o) << "<rect x=\"" << i * totalWidth << "\" y=\"" << j * totalWidth << "\" width=\"" << squareSize << "\" height=\"" << squareSize << "\""
					<< " fill=\"" << (gameOfLife.getCellAlive(i, j) ? aliveFill : deadFill) << "\" stroke-width=\"" << strokeWidth << "\""
					<< " stroke=\"" << stroke << "\"" << " /> " << std::endl;
			}
		}
		(*o) << "</svg>";
	}
}
