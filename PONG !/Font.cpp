
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
	if(!Launcher::switchedOn)
	{
		TTF_CloseFont(font) ;
		TTF_Quit() ;
	}
	
	SDL_Surface *tmp_surface = TTF_RenderText_Solid(font , text , color) ;
	return tmp_surface ;
}

SDL_Texture *Font::getText(TTF_Font *font, const char *text, SDL_Color color)
{
	if(!Launcher::switchedOn)
	{
		TTF_CloseFont(font) ;
		TTF_Quit() ;
	}
	
	SDL_Surface *tmp_surface = TTF_RenderText_Solid(font , text , color) ;
	SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(Launcher::renderer , tmp_surface) ;
	SDL_FreeSurface(tmp_surface) ;
	
	return fontTexture ;
}
