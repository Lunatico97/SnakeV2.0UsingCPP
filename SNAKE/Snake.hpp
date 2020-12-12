#pragma once

#include "Launcher.hpp"
#include "Body.hpp"
#include "Food.hpp"
#include "Music.hpp"

class Snake
{
	public :
		
		Snake() ;
		~Snake() ;
		
		void createGame() ;
		
		void displayGame() ;
		
		void updateGame() ;
		
		void quitGame() ;
		
		bool shouldGamePause() ;
		
	private :
		
		Mix_Chunk *get = Music::loadMusic("rsrc/goodypop.wav") ;
		bool stop ;
} ;
