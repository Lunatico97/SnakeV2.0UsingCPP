
#include "Snake.hpp"

Body *snakeBody = nullptr ;
Food *food = nullptr ;
int Body::retardation = 3 ;

Snake::Snake()
{
	
}

Snake::~Snake()
{
	
}

bool Snake::shouldGamePause()
{
	return stop ;
}

void Snake::createGame()
{
	snakeBody = new Body() ;
	food = new Food() ;
	snakeBody->createSnakeBody(SCR_W/2-PER_SEGMENT/2, SCR_H/2-PER_SEGMENT/2, PER_SEGMENT, PER_SEGMENT) ;
	snakeBody->createScoreBoard(0,0,100,20) ;
	snakeBody->createToxicBoard(0,SCR_H-20,120,20) ;
	srand(time(0)) ;
	food->generateFood(FOOD_PIXEL*(rand()%(SCR_W/FOOD_PIXEL)),FOOD_PIXEL*(rand()%(SCR_H/FOOD_PIXEL))) ;
	food->generateRune(FOOD_PIXEL*(rand()%(SCR_W/FOOD_PIXEL)),FOOD_PIXEL*(rand()%(SCR_H/FOOD_PIXEL))) ;
	stop = false ;
}

void Snake::displayGame()
{
	snakeBody->updatePositionAndTail() ;
	snakeBody->displayScoreBoard() ;
	snakeBody->displayToxicBoard() ;
	snakeBody->displayTimer(0,20,120,20) ;
	snakeBody->displaySnakeBody(0,255,0) ;
	food->displayRune() ;
	food->displayFood() ;
	
	if( snakeBody->getTime() != 0 && (snakeBody->getTime())%15 == 0)
	{
		food->generateRune(FOOD_PIXEL*(rand()%(SCR_W/FOOD_PIXEL)),FOOD_PIXEL*(rand()%(SCR_H/FOOD_PIXEL))) ;
	}
	
	if(!snakeBody->isSnakeAlive())
	{
		stop = true ;
		snakeBody->showMyScore(SCR_W/2-200,SCR_H/2-30,200,30) ;
		std::cout << "PRESS 'SPACE' TO RESTART" << std::endl ;
		
		if(Launcher::event.type == SDL_KEYDOWN && Launcher::event.key.keysym.sym == SDLK_SPACE)
		{	
		
			std::cout << "NEW GAME IN 3 SECONDS " << std::endl ;
			std::cout << "LAST SCORE : " << snakeBody->getScore() << std::endl ;
			SDL_Delay(3000) ; // 3 seconds delay : 3,2,1 - Go !
			snakeBody->reset(SCR_W/2-PER_SEGMENT/2, SCR_H/2-PER_SEGMENT/2, PER_SEGMENT, PER_SEGMENT) ;
			stop = false ;
		}	
		
	}
}

void Snake::updateGame()
{
	snakeBody->controlSnakeBody() ;
	
	SDL_Rect h = snakeBody->getHead() ;
	SDL_Rect f = food->getFood() ;
	SDL_Rect r = food->getRune() ;
	
	if(SDL_HasIntersection(&h, &f))
	{
		snakeBody->increaseTail() ;
		food->generateFood(FOOD_PIXEL*(rand()%(SCR_W/FOOD_PIXEL)),FOOD_PIXEL*(rand()%(SCR_H/FOOD_PIXEL))) ;
		Music::playMusic(get, 20) ;
	}
	
	if(snakeBody->getScore()<25) snakeBody->updateToxicity(100) ;
	if(snakeBody->getScore()>25 && snakeBody->getScore()<50) snakeBody->updateToxicity(50) ;
	if(snakeBody->getScore()>50 && snakeBody->getScore()<75) snakeBody->updateToxicity(5) ;
	if(snakeBody->getScore()>75 && snakeBody->getScore()<100) snakeBody->updateToxicity(4) ;
	if(snakeBody->getScore()>100 && snakeBody->getScore()<150) snakeBody->updateToxicity(3) ;
	if(snakeBody->getScore()>150) snakeBody->updateToxicity(2) ;
	if(snakeBody->getScore()>25) Body::retardation = 2 ;
	if(snakeBody->getScore()>50) Body::retardation = 1 ;
	if(snakeBody->getScore()>100) Body::retardation = 0 ;
	
	if(SDL_HasIntersection(&h, &r))
	{
		food->generateRune(-100,-100) ;	
	
		if(snakeBody->getScore()<25) snakeBody->reduceTail(100) ;
		if(snakeBody->getScore()>25 && snakeBody->getScore()<50) snakeBody->reduceTail(50) ;
		if(snakeBody->getScore()>50 && snakeBody->getScore()<75) snakeBody->reduceTail(5) ;
		if(snakeBody->getScore()>75 && snakeBody->getScore()<100) snakeBody->reduceTail(4) ;
		if(snakeBody->getScore()>100 && snakeBody->getScore()<150) snakeBody->reduceTail(3) ;
		if(snakeBody->getScore()>150) snakeBody->reduceTail(2) ;
			
		Music::playMusic(get, 20) ;
	}
	
	snakeBody->stayWithInTheScreen() ;

}

void Snake::quitGame()
{
	snakeBody->kill() ;
	snakeBody->clean() ;
	food->clean() ;
	Mix_FreeChunk(get) ;
}
