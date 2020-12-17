
   Conway's Game Of Life
   Author : Diwas Adhikari
   Email : lunaticoda123@gmail.com
   Algorithm : John H. Conway
   Graphics : SDL 2.x
   SDL_Wrapper Class - Oriented (Author : Diwas Adhikari)
   
   ~ Zero-player cellular automata/simulation
   
   -> Files included : Cell.hpp/.cpp
   
   -> Controls :            Keyboard =
   						{BACKSPACE - Clear The Screen & Pause The Automata}
   						{SPACE - Pause/Resume The Automata}
   						
   		   	    Mouse = 	
				 		{LEFT_CLICK - Revive a cell }
						{RIGHT_CLICK - Kill a cell }
						{LEFT_CLICK_HOLD & Drag - Revive cells}
						{RIGHT_CLICK_HOLD & Drag - Kill cells}
						
   -> Beginner Patterns : {LABEL : '#' : Alive Cell || '.' : Dead Cell}
   	 (also, includes some interesting patterns)
							
   						Block =         (Creates stable square block)
										. . . .
										. # # .
										. # # .
										. . . . 
   						
   					    Glider =        (Glides infinitely if, no barriers) 
									    . . . . .       . . . . .
							     		    . . # . .       . . # . .
								    	    . . . # .  or,  . # . . .
									    . # # # .       . # # # . 
									    . . . . .       . . . . .
						
						Eater =         (Eats a glider without disrupting itself)
										. . . . . .
										. # # . . .
										. # . . . .
										. . # # # .
										. . . . # .
										. . . . . . 
						
						Blinker =       (Blinks continously and never becomes stable)
										. . .     . . . . . 
										. # .     . # # # .
										. # . or, . . . . .
										. # . 
										. . .
									
					    Glider Gun =    (Creates glider infinitely)
			                   (Bill Cosper)		        . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
									        . . . . . . . . . . . . . . . . . . . . . . . . . # . . . . . . . . .
										. . . . . . . . . . . . . . . . . . . . . . . # . # . . . . . . . . .
										. . . . . . . . . . . . . # # . . . . . . # # . . . . . . . . . # # .
										. . . . . . . . . . . . # . . . # . . . . # # . . . . . . . . . # # .
										. # # . . . . . . . . # . . . . . # . . . # # . . . . . . . . . . . .
										. # # . . . . . . . . # . . . # . # # . . . . # . # . . . . . . . . .
										. . . . . . . . . . . # . . . . . # . . . . . . . # . . . . . . . . .
										. . . . . . . . . . . . # . . . # . . . . . . . . . . . . . . . . . .
										. . . . . . . . . . . . . # # . . . . . . . . . . . . . . . . . . . .
										. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
						          
				   4-8-12 Diamond =	    (Creates 4 gliders moving on axis away by 90 degrees)
				                        . . . . . . . . . . . . . .
				                        . . . . . # # # # . . . . .
				                        . . . . . . . . . . . . . .
				                        . . . # # # # # # # # . . .
				                        . . . . . . . . . . . . . .
				                        . # # # # # # # # # # # # .
				                        . . . . . . . . . . . . . .
				                        . . . # # # # # # # # . . .
				                        . . . . . . . . . . . . . .
				                        . . . . . # # # # . . . . .
				                        . . . . . . . . . . . . . .
					
					    Acorn =         (Creates methuselah i.e pattern that stabilizes after a long time with 13 gliders
			        (Charles Corderman)	     and some small patterns like blinkers, blocks as well as, a mango and a eater)
									        . . . . . . . . .
										. . # . . . . . .
										. . . . # . . . .
										. # # . . # # # .
										. . . . . . . . .
										
					Demonoid =          (Creates some patterns and change phase to create 12 blinkers at the end)
	                       (Achim Flammenkamp)                              . . . . . . . . . . . . . . . . . . .   
										. . . . # # . . . . . . # # . . . . . 
										. . . # . # . . . . . . # . # . . . . 
										. . . # . . . . . . . . . . # . . . . 
										# # . # . . . . . . . . . . # . # # . 
										# # . # . # . . # # . . # . # . # # . 
										. . . # . # . # . . # . # . # . . . . 
										. . . # . # . # . . # . # . # . . . . 
										# # . # . # . . # # . . # . # . # # . 
										# # . # . . . . . . . . . . # . # # . 
										. . . # . . . . . . . . . . # . . . . 
										. . . # . # . . . . . . # . # . . . .          
										. . . . # # . . . . . . # # . . . . . 
										. . . . . . . . . . . . . . . . . . . 
									
		  1-2-3 Oscillator =            (Creates an oscillator with three cells only in the rotor) 	
		   (Dave Buckingham)                                            . . . . . . . . . . . . 
		                                                                . . . # # . . . . . . . 
										. # . . # . . . . . . . 
										. # # . # . # # . . . . 
										. . # . # . . # . . . . 
										. . # . . . . # . # # . 
										. . . # # # . # . # # . 
										. . . . . . # . . . . . 
										. . . . . # . . . . . . 
										. . . . . # # . . . . . 
										. . . . . . . . . . . .
										
		1-2-3-4 Oscillator =            (Creates an oscillator with three cells with one vacant space in the rotor) 	
		   (Dave Buckingham)                                            . . . . . . . . . . . . .
		   								. . . . . . # . . . . . .
		                                                                . . . . . # . # . . . . .
										. . . . # . # . # . . . .
										. . . . # . . . # . . . .
										. # # . # . # . # . # # .
										. # . # . . . . . # . . .
										. . . . # # # # # . . . .
										. . . . . . . . . . . . .
										. . . . . . # . . . . . .
										. . . . . # . # . . . . .
										. . . . . . # . . . . . .
										. . . . . . . . . . . . .
										
		  Two-Glider Mess =             (Collides two gliders in this way to get 4 gliders, 4 blocks , 8 blinkers,
		                                 beehive and a ship)
		                                . . . . . . . . . . . . 
		                                . . . # . . . . . . . .
		                                . # . # . . . . . . . .
		                                . . # # . . . . . . . .
		                                . . . . . . . . . . # .
		                                . . . . . . . . # # . .
		                                . . . . . . . . . # # .
		                                . . . . . . . . . . . .
		                                
                     'A' For All =             (Creates a 4-way rotor)
		   (Dean Hickerson)             . . . . . . . . . . . . 
		                                . . . . . # # . . . . .
		                                . . . . # . . # . . . .
		                                . . . . # # # # . . . .
		                                . . # . # . . # . # . .
		                                . # . . . . . . . . # .
		                                . # . . . . . . . . # .
		                                . . # . # . . # . # . .
		                                . . . . # # # # . . . .
		                                . . . . # . . # . . . .
		                                . . . . . # # . . . . .
		                                . . . . . . . . . . . .
		                                 
		   								  
