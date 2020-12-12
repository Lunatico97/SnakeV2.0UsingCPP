
#pragma once
#include "Launcher.hpp"
#include "Texture.hpp"

class Font
{
	public :
		
		static TTF_Font *loadFont(const char *filename, int fontSize) ;
		
		static SDL_Surface *getSurface(TTF_Font *font, const char *text, SDL_Color color) ;
		
		static SDL_Texture *getText(TTF_Font *font, const char *text, SDL_Color color) ;
	
} ;
