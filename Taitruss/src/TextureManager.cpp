#include "../headers/TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(const char* filename, int width, int height)
{
	if (IMG_Load(filename) == NULL) {
		std::cout << "FAILED TO LOAD IMAGE" << SDL_GetError() << std::endl;
	}
	if (IMG_Load(filename)) {
		std::cout << "Loaded " << filename << std::endl;
	}
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Surface* scaledSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_BlitScaled(tmpSurface, NULL, scaledSurface, NULL);

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Interface::renderer, scaledSurface);
	if (tex == NULL) {
		std::cout << "Unable to create texture from image!" << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(tmpSurface);
	SDL_FreeSurface(scaledSurface);
	return tex;
}

SDL_Texture* TextureManager::LoadTextureSlice(const char* filename, int index, int& width, int& height)
{
	if (IMG_Load(filename))
	{
		const int number_image_location = index * 256;
		std::cout << "Loaded::" << filename <<"Indexing to: "<<number_image_location<<" pixels over"<< "\n";
		const SDL_Rect srcRect = { number_image_location,0,256,256 };
		SDL_Surface* sliced_surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
		SDL_Surface* tmp_surface = IMG_Load(filename);
		SDL_Surface* scaled_surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
		if (sliced_surface != nullptr)
		{
			SDL_BlitScaled(tmp_surface, &srcRect, sliced_surface, nullptr);
			SDL_BlitScaled(sliced_surface, nullptr, scaled_surface, nullptr);
			SDL_Texture* num_tex = SDL_CreateTextureFromSurface(Interface::renderer, sliced_surface);

			if (num_tex != nullptr)
			{
				SDL_FreeSurface(sliced_surface);
				SDL_FreeSurface(tmp_surface);
				SDL_FreeSurface(scaled_surface);
				return num_tex;
			}

		}

		std::cout << "Unable to create number texture from image!" << SDL_GetError() << std::endl;


	}
	else
	{
		std::cout << "FAILED TO LOAD IMAGE" << SDL_GetError() << std::endl;
		return nullptr;
	}
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect& src, SDL_Rect& dest)
{
	SDL_RenderCopy(Interface::renderer, tex, &src, &dest);
}
