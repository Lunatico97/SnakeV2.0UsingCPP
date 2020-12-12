
#pragma once
#include "Launcher.hpp"
#include "Texture.hpp"
#include "Music.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

class Pong
{
	public :
	
		Pong() ;
		~Pong() ;
	
		void createPong() ;
		
		void displayPong() ;
		
		void updatePong() ;
		
		bool isGameOver() ;
		
		bool didPlayerWin() ;
		
		void restart() ;
		
	private :
		bool isColliding(SDL_Rect a, SDL_Rect b)
		{
			if(
				a.x + a.w > b.x &&
				a.y + b.h > b.y &&
				b.x + b.w > a.x &&
				b.y + b.h > a.y
			  )
			{
				return true ;
			}
			else
				return false ;
		}
		
	bool checkCollision(SDL_Rect ball, SDL_Rect paddle)
	{
		float ballLeft = ball.x;
		float ballRight = ball.x + ball.w;
		float ballTop = ball.y;
		float ballBottom = ball.y + ball.h;

		float paddleLeft = paddle.x;
		float paddleRight = paddle.x + paddle.w;
		float paddleTop = paddle.y;
		float paddleBottom = paddle.y + paddle.h;

		if (ballLeft >= paddleRight) return false;
		if (ballRight <= paddleLeft) return false;
		if (ballTop >= paddleBottom) return false;
		if (ballBottom <= paddleTop) return false;
		else return true;
	}
		
		bool gameOver, win ;
		SDL_Surface *surface ;
		SDL_Rect rect ;
		std::string text ;
		SDL_Texture *texture ;
		SDL_Color red = {255,0,0,255} ;
		SDL_Color green = {0,255,0,255} ;
		SDL_Texture *bg = Texture::getImage("rsrc/bg.png") ;
		TTF_Font *font = Font::loadFont("rsrc/AGENCYR.ttf", 15) ;
		Mix_Chunk *bounce = Music::loadMusic("rsrc/bounce.wav") ;
		
} ;
