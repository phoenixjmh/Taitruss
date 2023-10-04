#pragma once
#include <string>
#include <vector>

#include "Bag.h"
#include "Tile.h"
class Piece {
public:
	bool CanRotate(ALL_PIECES type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares, int WIDTH, int HEIGHT);
	ALL_PIECES m_type;
	std::string m_facing;
	std::vector<Tile*> os;

	void UpdateRadius(std::vector<Tile*> occupiedSquares);
	std::vector<Tile*> GetRadius();
	void RefreshPiece();
	void Rotate() const;
	void RotateLong(std::vector<Tile*>occupiedSquares,std::vector<Tile> &squareObjects);



	Piece(ALL_PIECES type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares, int WIDTH, int HEIGHT) :
		m_type{ type },
		m_facing{ facing },
		m_allSquares{ allSquares },
		os{occupiedSquares},
		m_rotated{false}
		



	{};
private:
	bool m_rotated;
	std::vector<Tile>& m_allSquares;
	std::vector<Tile*> m_radius;
	bool BorderCheck(ALL_PIECES type, std::string facing, std::vector<Tile*> occupiedSquares, int WIDTH, int HEIGHT);
	bool NeighborCheck(ALL_PIECES type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares);
};