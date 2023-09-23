#include "../headers/TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename,int& width,int& height)
{
	if (IMG_Load(filename) == NULL){
		std::cout<<"FAILED TO LOAD IMAGE"<<SDL_GetError()<<std::endl;
		}
	if (IMG_Load(filename)) {
		std::cout << "Loaded " << filename << std::endl;
	}
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Surface* scaledSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_BlitScaled(tmpSurface, NULL, scaledSurface, NULL);

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Interface::renderer,scaledSurface);
	if (tex == NULL){
		std::cout << "Unable to create texture from image!" << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(tmpSurface);
	SDL_FreeSurface(scaledSurface);
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect &src, SDL_Rect &dest)
{
	SDL_RenderCopy(Interface::renderer, tex, &src, &dest);
}
