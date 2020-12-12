
#include "Ball.hpp"

Ball::Ball()
{
	
}

Ball::~Ball()
{
	
}

void Ball::createBall(int x, int y, int w, int h)
{
	ballRect = {x,y,w,h} ;
	velX = BALL_S/2 ;
	velY = 0 ;
}

void Ball::drawBall(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(Launcher::renderer, r, g, b, 255) ;
	SDL_RenderFillRect(Launcher::renderer, &ballRect) ;
}

void Ball::updateVelocity(int vx, int vy)
{
	velX = vx ;
	velY = vy ;
}
void Ball::updateBall()
{
	ballRect.x += velX ;
	ballRect.y += velY ;
	
	if(ballRect.x+BALL_W>=SCR_W)
	{
		velX =- velX ;
		deductCOM = true ;
	}
	if(ballRect.y+BALL_H>=SCR_H)
	{
		velY =- velY ;
	}
	if(ballRect.x <= 0)
	{
		velX =- velX ;
		deduct = true ;
	}
	if(ballRect.y <= 0)
	{
		velY =- velY ;
	}
	
}

void Ball::updateBallPosition(int x, int y)
{
	ballRect.x = x ;
	ballRect.y = y ;
	velX = BALL_S/2 ;
	velY = 0 ;
}

bool Ball::shouldDeductScore()
{
	return deduct ;
}

bool Ball::AIfail()
{
	return deductCOM ;
}

void Ball::avoidCOM()
{
	deductCOM = false ;
}

void Ball::avoidPlay()
{
	deduct = false ;
}

SDL_Rect Ball::getBall()
{
	return ballRect ;
}
