#include "Body.hpp"

Body::Body()
{
	
}

Body::~Body()
{

}

void Body::clean()
{
	Font::close(font) ;
	
	SDL_DestroyTexture(scoreTexture) ;
	SDL_DestroyTexture(timerTexture) ;
	SDL_DestroyTexture(gameOverTexture) ;
	SDL_DestroyTexture(finalTexture) ;
	SDL_DestroyTexture(toxicTexture) ;	
}

void Body::reduceTail(int n)
{
	nth_tailPos -= n ;
}

void Body::updateToxicity(int n)
{
	toxicity = n ;
}

void Body::kill()
{
	alive = false ;
}

void Body::createToxicBoard(int x, int y, int w, int h)
{
	toxicBoard = {x, y, w, h} ;
}


void Body::displayToxicBoard(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color a = {r,g,b} ;
	toxicText = "TOXICITY : " + std::to_string(toxicity) ;
	toxic = Font::getSurface(font, toxicText.c_str(), a) ;
	toxicTexture = Texture::createFromSurface(toxic) ;
	Texture::free_surface(toxic) ;
	SDL_RenderCopy(Launcher::renderer, toxicTexture, NULL, &toxicBoard) ;
}

void Body::createSnakeBody(int x, int y, int w, int h)
{
	headRect = {x,y,w,h} ;
	alive = true ;
	score = 0 ;
	secondsF = 0 ;
	seconds = 0 ;
	for(int i=0; i<nth_tailPos; i++)
	{
		tailRects[i] = {headRect.x-(PER_SEGMENT*(i+1)), headRect.y, PER_SEGMENT, PER_SEGMENT} ;
	}
}

void Body::reset(int x, int y, int w, int h)
{
	alive = true ;
	score = 0 ;
	secondsF = 0 ;
	seconds = 0 ;
	nth_tailPos = 5 ;
	Body::retardation = 3 ;
	headRect = {x,y,w,h} ;
}

SDL_Rect Body::getHead()
{
	return headRect ;
}

void Body::displaySnakeBody(Uint8 r, Uint8 g, Uint8 b)
{
	for(int i=0; i<nth_tailPos; i++)
	{
		SDL_SetRenderDrawColor(Launcher::renderer, 255,255,0,255) ;
		SDL_RenderFillRect(Launcher::renderer, &headRect) ;
		SDL_SetRenderDrawColor(Launcher::renderer, r, g, b, 255) ;	
		SDL_RenderFillRect(Launcher::renderer, &tailRects[i]) ;
	}
}

void Body::createScoreBoard(int x, int y, int w, int h)
{
	scoreBoard = {x, y, w, h} ;
}

void Body::displayTimer(int x, int y, int w, int h)
{
	timerRect = {x, y, w, h} ;
	
	if(alive)
	{
		secondsF += 1 ;
		if(secondsF > 59-(Body::retardation*10))
		{
			int temp = secondsF/(60-(Body::retardation*10)) ;
			seconds += temp ;
			secondsF = secondsF%(60-(Body::retardation*10)) ;
		}
	}
	
	timerText  = "TIME : " + std::to_string(seconds) + " s ";
	SDL_Color color = {255,255,255} ;
	timer = Font::getSurface(font, timerText.c_str(), color) ;
	timerTexture = Texture::createFromSurface(timer) ;
	Texture::free_surface(timer) ;
	SDL_RenderCopy(Launcher::renderer, timerTexture, NULL, &timerRect) ; 
}

void Body::displayScoreBoard(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color a = {r,g,b} ;
	scoreText = "COINS : " + std::to_string(score) ;
	sc = Font::getSurface(font, scoreText.c_str(), a) ;
	scoreTexture = Texture::createFromSurface(sc) ;
	Texture::free_surface(sc) ;
	SDL_RenderCopy(Launcher::renderer, scoreTexture, NULL, &scoreBoard) ;
}

int Body::getScore()
{
	return score+(seconds/10) ;
}

void Body::controlSnakeBody()
{
	
	if(Launcher::event.type == SDL_KEYDOWN)
	{
		switch(Launcher::event.key.keysym.sym)
		{
			case SDLK_UP :
				left = right = false ;
				if(!down)
				{
					up = true ;
					down = false ;
				}
				else
				{
					down = true ;
					up = false ;
				}
				break ;
			
			case SDLK_DOWN :
				left = right = false ;
				if(!up)
				{
					down = true ;
					up = false ;
				}
				else
				{
					up = true ;
					down = false ;
				}
				
				break ;
				
			case SDLK_LEFT :
				up = down = false ;
				if(!right)
				{
					left = true ;
					right = false ;
				}
				else
				{
					right = true ;
					left = false ;
				}
				break ;
				
			case SDLK_RIGHT :
				up = down = false ;
				if(!left)
				{
					right = true ;
					left = false ;
				}
				else
				{
					left = true ;
					right = false ;
				}
				break ;
			
			default :
				break ;
				
		}
	}
}

void Body::surpassScreen()
{
	if(headRect.x < 0)
	{
		headRect.x = (SCR_W-headRect.w ) ;
	}
	if(headRect.x > (SCR_W-headRect.w))
	{
		headRect.x = 0 ;
	}
	if(headRect.y < 0)
	{
		headRect.y = (SCR_H-headRect.h ) ;
	}
	if(headRect.y > (SCR_H-headRect.h))
	{
		headRect.y = 0 ;
	}
}

int Body::getTime()
{
	return seconds ;
}

void Body::stayWithInTheScreen()
{
	if(headRect.x < 0)
	{
		alive = false ;
		nth_tailPos = 0 ;
		headRect.x = 0 ;
	}
	if(headRect.x > (SCR_W-headRect.w))
	{
		alive = false ;
		nth_tailPos = 0 ;
		headRect.x = (SCR_W-headRect.w );
	}
	if(headRect.y < 0)
	{
		alive = false ;
		nth_tailPos = 0 ;
		headRect.y = 0 ;
	}
	if(headRect.y > (SCR_H-headRect.h))
	{
		alive = false ;
		nth_tailPos = 0 ;
		headRect.y = (SCR_H-headRect.h );
	}
	
}

void Body::increaseTail() 
{
	nth_tailPos += 1 ;
	score += 1 ;
}

void Body::updatePositionAndTail()
{
	if(up && !down)
	{
		headRect.y -= (PER_SEGMENT) ;
	}
	if(down && !up)
	{
		headRect.y += (PER_SEGMENT) ;
	}
	if(left && !right)
	{
		headRect.x -= (PER_SEGMENT) ;
	}
	if(right && !left)
	{
		headRect.x += (PER_SEGMENT);
	}
	
	//Main Algorithm
	
	prevX1 = tailRects[0].x ;
	prevY1 = tailRects[0].y ;
	tailRects[0].w = tailRects[0].h = PER_SEGMENT ;
	
	for(int i=1; i<nth_tailPos; i++)
	{
		if(right || left || up || down)
		{
			tailRects[0].x = headRect.x ;
			tailRects[0].y = headRect.y ;
			prevX2 = tailRects[i].x ;
			prevY2 = tailRects[i].y ;
			tailRects[i].x = prevX1 ;
			tailRects[i].y = prevY1 ;
			prevX1 = prevX2 ;
			prevY1 = prevY2 ;
		
			tailRects[i].w = tailRects[i].h = PER_SEGMENT ;
		}
		
		if(headRect.x == tailRects[i].x && headRect.y == tailRects[i].y)
		{
			alive = false ;
			nth_tailPos = 0 ;
		}
	}
	
	if(nth_tailPos <= 1)
	{
		alive = false ;
	}
}

bool Body::isSnakeAlive()
{
	return alive ;
}

void Body::showMyScore(int x, int y, int w, int h)
{
	gameOverRect = {x,y-h,w,h} ;
	finalRect = {x-50,y,w*3,h} ;
	
	gameOverText  = "    GAME OVER " ;
	scoreFinalText = "YOUR SCORE : COINS + (TIME/10) ~ " + std::to_string(score+(seconds/10)) ;
	SDL_Color a = {255,0,0} ;
	SDL_Color b = {0,0,255} ;
	over = Font::getSurface(font, gameOverText.c_str(), a) ;
	final = Font::getSurface(font, scoreFinalText.c_str(), b) ;
	gameOverTexture = Texture::createFromSurface(over) ;
	finalTexture = Texture::createFromSurface(final) ;
	Texture::free_surface(over) ;
	Texture::free_surface(final) ;
	SDL_RenderCopy(Launcher::renderer, gameOverTexture, NULL, &gameOverRect) ;
	SDL_RenderCopy(Launcher::renderer, finalTexture, NULL, &finalRect) ;
	
}
