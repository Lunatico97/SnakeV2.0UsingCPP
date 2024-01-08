"SnakeV2.0"
Author : Diwas Adhikari
Email : lunaticoda123@gmail.com
Graphics : SDL 2.x (SDL Wrapper Class - Diwas Adhikari)
Files Included : -> Snake.hpp/.cpp
		 -> Food.hpp/.cpp
 		 -> Body.hpp/.cpp
Features: 
-> Introduces a new collectible token ~ 'Rune' which can either kill a snake if deadly enough or, can save its life to shrink its length !  
-> With everything that a classic arcade 'Snake' game offers, a new parameter called toxicity is linked to the token !
-> Scores is based on both collection of coins and survival time ! Make sure the clock keeps ticking !
Controls : Keyboard -> (UP/DOWN/LEFT/RIGHT) - Movement
                    -> SPACE - Restart After Game Over
		    -> ESCAPE - Exit The Game
How to install ? :
<For Windows>
Compile the source using C++ compiler and keep the runtime dependencies of SDL2, SDL2_ttf, SDL2_image, SDL2_mixer, zlib (.dll) near the executable file (.exe)
<For every OS>
Put linkers : -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer  
