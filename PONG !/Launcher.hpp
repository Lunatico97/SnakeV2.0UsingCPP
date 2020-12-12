
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

#define SCR_W 800
#define SCR_H 400
#define PI 3.141569

class Launcher
{
	public:
		
		void initScreen(const char *title, int width, int height, int flag) ;
		
		void handleEvents() ;
		
		void updateScreen() ;
		
		void renderScreen() ;
		
		void quit() ;
		
		bool isRunning() ;

		static SDL_Renderer *renderer ;
		
		static SDL_Event event ;
		
		static bool switchedOn ;
		
	private:
		
		SDL_Window *window ;
		
} ;
