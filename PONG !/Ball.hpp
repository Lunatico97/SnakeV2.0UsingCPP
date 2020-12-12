#pragma once

#include "Launcher.hpp"
#define BALL_W 10
#define BALL_H 10
#define BALL_S 9

class Ball
{
	public :
			Ball() ;
			~Ball() ;
			
			void createBall(int x, int y, int w, int h) ;
			
			void drawBall(Uint8 r, Uint8 g, Uint8 b) ;
			
			void updateBall() ;
			
			void updateVelocity(int vx, int vy) ;
			
			SDL_Rect getBall() ;
			
			void updateBallPosition(int x, int y) ;
			
			bool shouldDeductScore() ;
			
			void avoidPlay() ;
			
			void avoidCOM() ;
			
			bool AIfail() ;
		
		
	private :
	
		SDL_Rect ballRect ;
		float velX, velY ;
		bool deduct, deductCOM ;
} ;
