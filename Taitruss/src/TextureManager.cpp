#include "../headers/TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	if (IMG_Load(filename) == NULL) {
		std::cout << "FAILED TO LOAD IMAGE" << SDL_GetError() << std::endl;
	}
	if (IMG_Load(filename)) {
		std::cout << "Loaded " << filename << std::endl;
	}
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Interface::renderer, tmpSurface);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

	if (tex == NULL) {
		std::cout << "Unable to create texture from image!" << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(tmpSurface);
	return tex;
}



void TextureManager::Draw(SDL_Texture* tex, SDL_Rect& src, SDL_Rect& dest)
{
	SDL_RenderCopy(Interface::renderer, tex, &src, &dest);
}
