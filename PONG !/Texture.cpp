
#include "Texture.hpp"

SDL_Surface *Texture::loadSurface(const char *filename)
{
	SDL_Surface *surface = IMG_Load(filename) ;
	
	if(surface == nullptr)
	{
		std::cout << "\nTexture Loader Diagnosis -> " << std::endl ;
		std::cout << "Error loading the image : " << filename << std::endl << "{Troubleshoot : " << SDL_GetError() << "}\n" << std::endl ; 
	}
	return surface ;
}

SDL_Texture *Texture::createTextureFromSurface(SDL_Surface *s)
{
	SDL_Texture *texture  = SDL_CreateTextureFromSurface(Launcher::renderer, s) ;
	return texture ;
}

void Texture::free_surface(SDL_Surface *s)
{
	SDL_FreeSurface(s) ;
}

SDL_Texture *Texture::getImage(const char *filename)
{
	SDL_Surface *surface = IMG_Load(filename) ;
	if(surface == nullptr)
	{
		std::cout << "\nTexture Loader Diagnosis -> " << std::endl ;
		std::cout << "Error loading the image : " << filename << std::endl << "{Troubleshoot : " << SDL_GetError() << "}\n" << std::endl ; 
	}
	SDL_Texture *texture  = SDL_CreateTextureFromSurface(Launcher::renderer, surface) ;
	SDL_FreeSurface(surface) ;
	return texture ;
}
