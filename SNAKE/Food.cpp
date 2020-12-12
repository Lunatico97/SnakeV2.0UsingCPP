
#include "Food.hpp"

Food::Food()
{
	
}

Food::~Food()
{

}

void Food::clean()
{
	SDL_DestroyTexture(coinTexture) ;
	SDL_DestroyTexture(runeTexture) ;
}

void Food::generateFood(int x, int y)
{
	foodRect={x,y,FOOD_PIXEL,FOOD_PIXEL} ;
}

void Food::generateRune(int x, int y)
{
	runeRect={x,y,FOOD_PIXEL,FOOD_PIXEL} ;
}

SDL_Rect Food::getFood()
{
	return foodRect ;
}

SDL_Rect Food::getRune()
{
	return runeRect ;
}

void Food::displayRune()
{
	int timeR = (SDL_GetTicks()/100%4) ;
	sRect.x = runeSprites[timeR].first ;
	sRect.y = runeSprites[timeR].second ;
	sRect.w = sRect.h = 16 ;
	SDL_RenderCopy(Launcher::renderer, runeTexture, &sRect, &runeRect) ;
}

void Food::displayFood()
{
	int timeF = (SDL_GetTicks()/100%4) ;
	sourceRect.x = coinSprites[timeF].first ;
	sourceRect.y = coinSprites[timeF].second ;
	sourceRect.w = sourceRect.h = 10 ;
	SDL_RenderCopy(Launcher::renderer, coinTexture, &sourceRect, &foodRect) ;
}
