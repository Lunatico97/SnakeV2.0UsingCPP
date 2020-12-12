#include "Pong.hpp"

Paddle *leftPaddle = nullptr ;
Paddle *rightPaddle = nullptr ;
Ball *ball = nullptr ;

Pong::Pong()
{
	leftPaddle = new Paddle() ;
	rightPaddle = new Paddle() ;
	ball = new Ball() ;
	gameOver = false ;
	win = false ;
}

Pong::~Pong()
{
	SDL_DestroyTexture(texture) ;
}

void Pong::restart()
{
	gameOver = false ;
	win = false ;
	rightPaddle->resetScore() ;
	leftPaddle->resetScore() ;
}

void Pong::createPong()
{
	//32 is just space between paddle and left side of screen
	leftPaddle->createPaddle(32 , SCR_H/2-PAD_H/2, PAD_W, PAD_H ) ;
	//100 is just space between paddle and left side of screen
	leftPaddle->createScoreBoard(200, 50, SCORE_W , SCORE_H) ;
	rightPaddle->createPaddle(SCR_W-32-PAD_W/2 , SCR_H/2-PAD_H/2  , PAD_W , PAD_H ) ;
	rightPaddle->createScoreBoard(SCR_W-200-SCORE_W/2, 50, SCORE_W , SCORE_H) ;
	ball->createBall(SCR_W/2-BALL_W/2, SCR_H/2-BALL_H/2, BALL_W, BALL_H) ;
	leftPaddle->activateTurn() ;
	
}

void Pong::displayPong()
{
	SDL_RenderCopy(Launcher::renderer,bg,NULL,NULL) ;
	
	if(gameOver)
	{
		text = "GAME OVER" ;
		rect = {SCR_W/2-400/2,SCR_H/2-50,400,50} ;
		surface = Font::getSurface(font, text.c_str(), red) ;
		texture = Texture::createTextureFromSurface(surface) ;
		SDL_RenderCopy(Launcher::renderer, texture, NULL, &rect) ;
		Texture::free_surface(surface) ;
		std::cout << "PRESS 'SPACE' TO RESTART !" << std::endl ;
	}
	if(win)
	{
		text = "YOU WON !" ;
		rect = {SCR_W/2-400/2,SCR_H/2-50,400,50} ;
		surface = Font::getSurface(font, text.c_str(), green) ;
		texture = Texture::createTextureFromSurface(surface) ;
		SDL_RenderCopy(Launcher::renderer, texture, NULL, &rect) ;
		Texture::free_surface(surface) ;
		std::cout << "PRESS 'SPACE' TO RESTART !" << std::endl ;
	}
	
	leftPaddle->displayPaddle(255,0,0) ;
	leftPaddle->displayScoreBoard(255,255,255) ;
	rightPaddle->displayPaddle(0,0,255) ;
	rightPaddle->displayScoreBoard(255,255,255) ;
	ball->drawBall(255,255,255) ;
}

bool Pong::isGameOver()
{
	return gameOver ;
}

bool Pong::didPlayerWin()
{
	return win ;
}

void Pong::updatePong()
{ 	
	if(ball->shouldDeductScore())
	{
		leftPaddle->deductScore() ;
		leftPaddle->updatePosition(32 , SCR_H/2-PAD_H/2) ;
		rightPaddle->updatePosition(SCR_W-32-PAD_W/2 , SCR_H/2-PAD_H/2 ) ;
		ball->updateBallPosition(SCR_W/2-BALL_W/2, SCR_H/2-BALL_H/2) ;
		ball->updateVelocity(BALL_S/2, 0) ;
		ball->avoidPlay() ;
	}
	if(ball->AIfail())
	{
		rightPaddle->deductScore() ;
		leftPaddle->updatePosition(32 , SCR_H/2-PAD_H/2) ;
		rightPaddle->updatePosition(SCR_W-32-PAD_W/2 , SCR_H/2-PAD_H/2 ) ;
		ball->updateBallPosition(SCR_W/2-BALL_W/2, SCR_H/2-BALL_H/2) ;
		ball->updateVelocity(BALL_S/2, 0) ;
		ball->avoidCOM() ;
	}
	
	if(leftPaddle->getScore() == 0) gameOver = true ;
	if(rightPaddle->getScore() == 0) win = true ;
	
	leftPaddle->stayWithInTheScreen() ;
	rightPaddle->stayWithInTheScreen() ;
	leftPaddle->controlPaddle() ;
	ball->updateBall() ;
	
	SDL_Rect l = leftPaddle->getPaddle() ;
	SDL_Rect r = rightPaddle->getPaddle() ;
	SDL_Rect b = ball->getBall() ;
	
	rightPaddle->launchAI(b) ;
	
	if(checkCollision(l, b))
	{
		double angleLeft = leftPaddle->getHitAngle(b) ;
		ball->updateVelocity(BALL_S*cos(angleLeft), BALL_S*sin(angleLeft)) ;
		leftPaddle->controlPaddle() ;
		Music::playMusic(bounce,20) ;
	}
	
	if(checkCollision(r, b))
	{
		double angleRight = rightPaddle->getHitAngle(b) ;
		ball->updateVelocity(-BALL_S*cos(angleRight), -BALL_S*sin(angleRight)) ;
		leftPaddle->controlPaddle() ;
		Music::playMusic(bounce,20) ;
	}
	
}

