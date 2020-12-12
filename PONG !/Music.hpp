
#pragma once
#include "Launcher.hpp"

class Music
{
	public :
		
		static Mix_Chunk *loadMusic(const char *filename) ;
		
		static void playMusic(Mix_Chunk *chunk, int volume) ;

} ;
