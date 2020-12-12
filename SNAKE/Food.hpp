#pragma once

#include "Launcher.hpp"
#include "Texture.hpp"
#define FOOD_PIXEL 20

class Food
{
	public :
		
		Food() ;
		~Food() ;
		
		void generateFood(int x, int y) ;
		
		SDL_Rect getFood() ;
		
		void displayFood() ;
		
		void generateRune(int x, int y) ;
		
		SDL_Rect getRune() ;
		
		void displayRune() ;
		
		void clean() ;
	private :
		
		SDL_Rect foodRect, sourceRect, runeRect, sRect ;
		SDL_Texture *coinTexture = Texture::loadTexture("rsrc/Coin.png") ;
		std::vector<std::pair<int,int>> coinSprites = {{0,0},{10,0},{20,0},{30,0}} ;
		SDL_Texture *runeTexture = Texture::loadTexture("rsrc/Rune.png") ;
		std::vector<std::pair<int,int>> runeSprites = {{0,0},{16,0},{32,0},{48,0}} ;
} ;
