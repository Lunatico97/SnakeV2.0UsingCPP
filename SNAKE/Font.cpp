
#include "Font.hpp"

TTF_Font *Font::loadFont(const char *filename, int fontSize)    
{
	TTF_Init() ;
	TTF_Font *font  = TTF_OpenFont(filename, fontSize) ;
	
	if(font == nullptr)
	{
		std::cout << "\nError loading fonts : " << filename << std::endl ;
		std::cout << "{Troubleshoot : " << TTF_GetError() << "}" << std::endl ;
	}
	
	else
	{
		std::cout << "Font Renderer Activated ..." << std::endl ;
	}
	
	return font ;
}

SDL_Surface *Font::getSurface(TTF_Font *font, const char *text, SDL_Color color)
{                      
	SDL_Surface *tmp_surface = TTF_RenderText_Solid(font , text , color) ;	
	return tmp_surface ;
}

void Font::close(TTF_Font *f)
{
	TTF_CloseFont(f) ;
	TTF_Quit() ;
}
