
#pragma once
#include "Launcher.hpp"

class Texture 
{
	public :
		
		static SDL_Surface *loadSurface(const char *filename) ;
		static SDL_Texture *createTextureFromSurface(SDL_Surface *s) ;
		static void free_surface(SDL_Surface *s) ;	
		
		static SDL_Texture *getImage(const char *filename) ;
} ;
