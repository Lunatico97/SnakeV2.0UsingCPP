
#include "Launcher.hpp"
#include "Texture.hpp"
#include "Music.hpp"
#include "Font.hpp"
#include "Pong.hpp"

SDL_Renderer *Launcher::renderer = nullptr ;
bool Launcher::switchedOn ;
SDL_Event Launcher::event ;
Pong *pong = nullptr ;

bool Launcher::isRunning()
{
	return switchedOn ;
}

void Launcher::initScreen(const char *title, int width, int height, int flag)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL 2.0 FAILED TO INITIALIZE ! " << std::endl ;
	}
	
	std::cout << "SDL 2.0 INITIALIZED SUCCESSFULLY ! " << std::endl ;
	window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,flag) ;
	renderer = SDL_CreateRenderer(window, -1, 0) ;
	switchedOn = true ;

	pong = new Pong() ;
	pong->createPong() ;
}

void Launcher::handleEvents()
{
	SDL_PollEvent(&event) ;
	if(event.type == SDL_QUIT)
	{
		switchedOn = false ;
	}
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE :
				switchedOn = false ;
				break ;
			
			case SDLK_SPACE :
				pong->restart() ;
				break ;
			
			default :
				break ;
				
		}
	}
}

void Launcher::quit()
{
	std::cout << "SDL 2.0 TERMINATED ! " << std::endl ;
	SDL_DestroyRenderer(renderer) ;
	SDL_DestroyWindow(window) ;
	SDL_Quit() ;
}

void Launcher::updateScreen()
{
	if(!pong->isGameOver() || pong->didPlayerWin())
	pong->updatePong() ;
	
}

void Launcher::renderScreen()
{
	SDL_RenderClear(renderer) ;
	
	pong->displayPong() ;
	
	SDL_SetRenderDrawColor(renderer, 0,0,0,255) ;
	SDL_RenderPresent(renderer) ;
}
