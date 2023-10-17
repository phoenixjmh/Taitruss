#pragma once
#include<vector>
#include "TextureManager.h"



class Scoreboard
{
public:
	int level;
	int score;
	bool blink;
	bool isBlinking;
	int blinkTimes;
	int blinkStartTime;
	int winWidth;
	int winHeight;
	int TOTAL_CLEARED_ROWS;
	
	int blockResolution = 256;
	const int bannerXRes = 320;
	const int bannerYRes = 190;
	const char* filePathBanner = "res/img/Score-Banner.png";
	const char* filePathBlankSquare = "res/img/BlankBorderBox.png";
	const char* filePathLevelBanner = "res/img/Level_Banner.png";
	void Draw();
	void AddPoints(int cleared);
	void Reset();
	void GetTextures();
	void Update();
	void GetLevelNumberTexture();
	void CheckLevel();
	SDL_Texture* banner;
	SDL_Texture* levelBanner;
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
	SDL_Texture* currentLevelNumber;
	Scoreboard(int block_resolution) :

		level(1),
		score(0),
		blinkTimes(8),
		TOTAL_CLEARED_ROWS(0),
		banner{ TextureManager::LoadTexture(filePathBanner) },
		levelBanner{TextureManager::LoadTexture(filePathLevelBanner)},
		zero{ TextureManager::LoadTexture("res/img/n_0.png") },
		one{ TextureManager::LoadTexture("res/img/n_1.png") },
		two{ TextureManager::LoadTexture("res/img/n_2.png") },
		three{ TextureManager::LoadTexture("res/img/n_3.png") },
		four{ TextureManager::LoadTexture("res/img/n_4.png") },
		five{ TextureManager::LoadTexture("res/img/n_5.png") },
		six{ TextureManager::LoadTexture("res/img/n_6.png") },
		seven{ TextureManager::LoadTexture("res/img/n_7.png") },
		eight{ TextureManager::LoadTexture("res/img/n_8.png") },
		nine{ TextureManager::LoadTexture("res/img/n_9.png") },
		blankSquare{ TextureManager::LoadTexture(filePathBlankSquare) },

		src{ SDL_Rect{0, 0, blockResolution,blockResolution} },
		dest{ SDL_Rect{0, 0, 50,50} }
	{};

};
