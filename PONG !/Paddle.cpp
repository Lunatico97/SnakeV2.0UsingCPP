
#include "Paddle.hpp"

Paddle::Paddle()
{
	
}

Paddle::~Paddle()
{
	
}

SDL_Rect Paddle::getPaddle()
{
	return paddleRect ;
}

void Paddle::controlPaddle()
{
	if(Launcher::event.type == SDL_KEYDOWN)
	{
		switch(Launcher::event.key.keysym.sym)
		{
			case SDLK_UP :
				paddleRect.y -= MOVE ;
				break ;
				
			case SDLK_DOWN :
				paddleRect.y += MOVE ;
				break ;
			
			default:
				break ;
		}
	}
}

void Paddle::createPaddle(int x, int y, int w, int h)
{
	paddleRect = {x,y,w,h} ;
	scoreCount = 3 ;
}

void Paddle::deductScore()
{
	scoreCount -=1 ;
}

void Paddle::updatePosition(int x, int y)
{
	paddleRect.x = x ;
	paddleRect.y = y ;
}

void Paddle::incrementScore()
{
	scoreCount += 1 ;
}

void Paddle::loseTurn()
{
	turn = false ;
}

void Paddle::activateTurn()
{
	turn = true ;
}

void Paddle::createScoreBoard(int x, int y, int w, int h)
{
   scoreRect = {x,y,w,h} ;
}

void Paddle::displayScoreBoard(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color a = {r,g,b} ;
	scoreText = std::to_string(scoreCount) ;
    scoreBoard = Font::getText(font, scoreText.c_str(), a) ;
	SDL_RenderCopy(Launcher::renderer, scoreBoard, NULL, &scoreRect) ;
}

void Paddle::displayPaddle(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(Launcher::renderer, r,g,b,255) ;
	SDL_RenderFillRect(Launcher::renderer, &paddleRect) ;
}

void Paddle::updatePaddle()
{
	
}

int Paddle::getScore()
{
	return scoreCount ;
}

bool Paddle::isItMyTurn()
{
	return turn ;
}

void Paddle::stayWithInTheScreen()
{
	if(paddleRect.y<0+BORDER)
	{
		paddleRect.y = 0+BORDER ;
	}
	if(paddleRect.y + paddleRect.h + BORDER> SCR_H)
	{
		paddleRect.y = SCR_H-paddleRect.h - BORDER ;
	}
}

void Paddle::resetScore()
{
	scoreCount = 3 ;
}

double Paddle::getHitAngle(SDL_Rect a)
{
	if(SDL_HasIntersection(&paddleRect, &a))
	{
		double relativeSite = (paddleRect.y+(paddleRect.h/2))-(a.y+(a.h/2)) ;
		double normalizeSite = relativeSite/(paddleRect.h) ;
		double angle = normalizeSite*(3*PI/2) ;
		return angle ;
	}
}

void Paddle::launchAI(SDL_Rect b)
{
	if(b.y > paddleRect.y+(paddleRect.h/2))
	{
		paddleRect.y += MOVE ;
	}
	if(b.y < paddleRect.y+(paddleRect.h/2))
	{
		paddleRect.y -= MOVE ;
	}
}
