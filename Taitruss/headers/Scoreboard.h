#pragma once
#include<vector>
#include "TextureManager.h"



class Scoreboard
{
public:
	int score;
	int winWidth;
	int winHeight;
	int& blockResolution;
	const char* filePathNumbers = "res/img/Numbers.png";
	const char* filePathBanner = "res/img/Score-Banner.png";
	const char* filePathBlankSquare = "res/img/BlankSquare.png";
	void Draw();
	void AddPoint();
	void GetTextures();
	SDL_Texture* banner;
	SDL_Texture* zero;
	SDL_Texture* one;
	SDL_Texture* two;
	SDL_Texture* three;
	SDL_Texture* four;
	SDL_Texture* five;
	SDL_Texture* six;
	SDL_Texture* seven;
	SDL_Texture* eight;
	SDL_Texture* nine;
	SDL_Texture* blankSquare;
	SDL_Rect src, dest;
	std::vector<SDL_Texture*> texturesToRender;
	Scoreboard(int block_resolution) :
		score(0),
		blockResolution(block_resolution),
		banner{ TextureManager::LoadTexture(filePathBanner, blockResolution, blockResolution) },
		zero{ TextureManager::LoadTextureSlice(filePathNumbers, 0, block_resolution, block_resolution) },
		one{ TextureManager::LoadTextureSlice(filePathNumbers, 1, block_resolution, block_resolution) },
		two{ TextureManager::LoadTextureSlice(filePathNumbers, 2, block_resolution, block_resolution) },
		three{ TextureManager::LoadTextureSlice(filePathNumbers, 3, block_resolution, block_resolution) },
		four{ TextureManager::LoadTextureSlice(filePathNumbers, 4, block_resolution, block_resolution) },
		five{ TextureManager::LoadTextureSlice(filePathNumbers, 5, block_resolution, block_resolution) },
		six{ TextureManager::LoadTextureSlice(filePathNumbers, 6, block_resolution, block_resolution) },
		seven{ TextureManager::LoadTextureSlice(filePathNumbers, 7, block_resolution, block_resolution) },
		eight{ TextureManager::LoadTextureSlice(filePathNumbers, 8, block_resolution, block_resolution) },
		nine{ TextureManager::LoadTextureSlice(filePathNumbers, 9, block_resolution, block_resolution) },
		blankSquare{ TextureManager::LoadTexture(filePathBlankSquare, blockResolution, blockResolution) },

		src{ SDL_Rect{0, 0, blockResolution,blockResolution} },
		dest{ SDL_Rect{0, 0, 50,50} }
	{};

};
