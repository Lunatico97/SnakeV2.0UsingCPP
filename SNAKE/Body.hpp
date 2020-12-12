#pragma once

#include "Launcher.hpp"
#include "Font.hpp"
#define MAX 200
#define PER_SEGMENT 10

#define FONT_SIZE 20

class Body
{
	public :
		
		Body() ;
		~Body() ;
		
		void createSnakeBody(int x, int y, int w, int h) ;
		
		void displaySnakeBody(Uint8 r, Uint8 g, Uint8 b) ;
		
		void createScoreBoard(int x, int y, int w, int h) ;
		
		void displayScoreBoard(Uint8 r=255, Uint8 g=255, Uint8 b=255) ;
		
		void createToxicBoard(int x, int y, int w, int h) ;
		
		void displayToxicBoard(Uint8 r=255, Uint8 g=255, Uint8 b=255) ;
		
		void controlSnakeBody() ;
		
		SDL_Rect getHead() ;
		
		void updatePositionAndTail() ;
		
		void stayWithInTheScreen() ;
		
		void surpassScreen() ;
		
		void reduceTail(int n) ;
		
		bool isSnakeAlive() ;
		
		void kill() ;
		
		void showMyScore(int x, int y, int w, int h) ;
		
		void increaseTail() ;
		
		int getScore() ;
		
		void clean() ;
		
		void reset(int x, int y, int w, int h) ;
		
		int getTime() ;
		
		void displayTimer(int x, int y, int w, int h) ;
		
		void updateToxicity(int n) ;
		
		static int retardation ;
		
	private :
		
		SDL_Rect headRect, tailRects[MAX] ;
		int nth_tailPos=5 ;
		bool alive ;
		int prevX1, prevY1, prevX2, prevY2 ;
		bool up, down, left, right, stop ;
		int score ;
		
		SDL_Surface *sc , *timer, *toxic, *final, *over ;
		SDL_Texture *scoreTexture, *timerTexture , *gameOverTexture, *finalTexture, *toxicTexture;
		TTF_Font *font = Font::loadFont("rsrc/AGENCYR.ttf", FONT_SIZE) ;
		SDL_Rect scoreBoard, timerRect, gameOverRect, finalRect, toxicBoard ;
		std::string scoreText, timerText, scoreFinalText, gameOverText , toxicText;
		int secondsF=0 , seconds=0 ;
		int toxicity ;
} ;
