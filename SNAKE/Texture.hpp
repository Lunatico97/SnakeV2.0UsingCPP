
#pragma once
#include "Launcher.hpp"

class Texture 
{
	public :
		
		static SDL_Texture *loadTexture(const char *filename) ;
		
		static SDL_Texture *createFromSurface(SDL_Surface *s) ;
		
		static void free_surface(SDL_Surface *s) ;
	
} ;
