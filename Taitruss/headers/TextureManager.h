#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Interface.h"
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename, int& width, int& height);
	static SDL_Texture* LoadTextureSlice(const char* filename,int index, int& width, int& height);
	static void Draw(SDL_Texture* tex, SDL_Rect &src, SDL_Rect &dest);
};