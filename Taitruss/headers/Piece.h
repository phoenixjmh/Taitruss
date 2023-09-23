#pragma once
#include <string>
#include <vector>
#include "Tile.h"
class Piece {
public:
	bool CanRotate(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares, int WIDTH, int HEIGHT);
	std::string m_type;
	std::string m_facing;
	std::vector<Tile*> os;

	void UpdateRadius(std::vector<Tile*> occupiedSquares);
	std::vector<Tile*> GetRadius();
	void RefreshPiece();
	void Rotate() const;
	void RotateLong(std::vector<Tile*>occupiedSquares,std::vector<Tile> &squareObjects);



	Piece(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares, int WIDTH, int HEIGHT) :
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
	bool BorderCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, int WIDTH, int HEIGHT);
	bool NeighborCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares);
};