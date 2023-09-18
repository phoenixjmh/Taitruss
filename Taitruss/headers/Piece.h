#pragma once
#include <string>
#include <vector>
#include "Tile.h"
class Piece {
public:
	static bool CanRotate(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile> &allSquares,int WIDTH,int HEIGHT);
	std::string m_type;
	std::string m_facing;

	
	Piece(std::string type,std::string facing,std::vector<Tile*> occupiedSquares,std::vector<Tile>&allSquares,int WIDTH,int HEIGHT):
		m_type{type},
		m_facing{facing}
	
	
	{};
private:
	std::vector<Tile*> m_radius;
	static bool BorderCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, int WIDTH, int HEIGHT);
	static bool NeighborCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile> &allSquares);
	std::vector<Tile*> GetRadius(std::string type,std::string facing,std::vector<Tile*> occupiedSquares , std::vector<Tile> &allSquares);
};