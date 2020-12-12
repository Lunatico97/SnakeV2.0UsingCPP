
#include "Timer.hpp"

double Timer::setFraps(int fraps, Uint32 beforeCountFraps, int delayFlag )
{
	periodTicks = (1000/fraps) ;
	deltaTicks = SDL_GetTicks() - beforeCountFraps ; 
	
	switch(delayFlag)
		{
			case CAP_LIMIT_DISABLE :
				if(deltaTicks/1000 < periodTicks)
				{
					deltaTime = periodTicks - deltaTicks/1000 ;
				}
				break ;
				
			case CAP_LIMIT_ENABLE :
				if(deltaTicks/1000 < periodTicks)
				{
					deltaTime = periodTicks - deltaTicks/1000 ;
				}
				SDL_Delay(deltaTime) ;
				break ;
				
			default :
				break ;		
		}
	
	return deltaTime ;
} 

void Timer::displayFraps(double deltaTime)
{
	std::cout << "FPS : " << 1000/deltaTime << std::endl ;	
}
