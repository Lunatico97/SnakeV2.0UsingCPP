#pragma once

#include "Launcher.hpp"
#include "Font.hpp"
#define PAD_W 7
#define PAD_H SCR_H/4
#define SCORE_W 25
#define SCORE_H 20
#define MOVE 15
#define BORDER 10

class Paddle
{
	public :
	
		Paddle() ;
		~Paddle() ;
		
		void createPaddle(int x, int y, int w, int h) ;
		
		void createScoreBoard(int x, int y, int w, int h) ;
		
		void displayScoreBoard(Uint8 r, Uint8 g, Uint8 b) ;
		
		void displayPaddle(Uint8 r, Uint8 g, Uint8 b) ;
		
		void controlPaddle() ;
		
		void updatePaddle() ;
		
		int getScore() ;
		
		void deductScore() ;
		
		void updatePosition(int x, int y) ;
		
		bool isItMyTurn() ;
		
		void activateTurn() ;
		
		void loseTurn() ;
		
		void stayWithInTheScreen() ;
		
		void resetScore() ;
		
		SDL_Rect getPaddle() ;
		
		void incrementScore() ;

		double getHitAngle(SDL_Rect a) ;
		
		void launchAI(SDL_Rect b) ;
		
	private :
		
		std::string scoreText ;
		int scoreCount ;
		SDL_Rect paddleRect, scoreRect ;
		SDL_Texture *scoreBoard ;
	
		bool turn ;
		TTF_Font *font = Font::loadFont("rsrc/AGENCYR.ttf", 15) ;
		
} ;
