
#pragma once
#include "Launcher.hpp"
#define CAP_LIMIT_ENABLE 1
#define CAP_LIMIT_DISABLE 0

class Timer
{
	public :
		double setFraps(int fraps, Uint32 beforeCountFraps, int delayFlag) ;
		
		void displayFraps(double deltaTime) ;
		
	private :
		double periodTicks ;
		double deltaTime ;
		int deltaTicks ;
	
} ;
