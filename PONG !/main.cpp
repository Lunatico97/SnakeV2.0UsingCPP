
#include "Launcher.hpp"
#include "Timer.hpp"

int main(int argc, char** argv) {
	
	Launcher *launcher = nullptr ;
	launcher = new Launcher() ;
	
	Timer *timer = nullptr ;
	timer = new Timer() ;
	
	launcher->initScreen(" PONG ! ", SCR_W , SCR_H, 0 ) ;
	
	while(launcher->isRunning())
	{
		Uint32 beforeTicks = SDL_GetTicks() ;
		
		launcher->handleEvents() ;
		launcher->updateScreen() ;	
		launcher->renderScreen() ;
		
		double deltaTime = timer->setFraps(60, beforeTicks, CAP_LIMIT_ENABLE) ;
		timer->displayFraps(deltaTime) ;
	}
	
	launcher->quit() ;
	 
	return 0;
}
