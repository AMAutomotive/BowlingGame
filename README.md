# BowlingGame
Project: Bowling Game
  
1. This implements a program for calculating the score of a single player in Bowling.

2. Game Rules and Input:
   
   A. bowling game consists of 10 frames.
   B. Each frame, the player has two tries to knock down 10 pins with a bowling ball.
   C. The score for the frame is the total of knocked down pins, plus bonuses for strikes and spared.
   D. A Spare is when a player knocks down all 10 pins in two tries.
      The bonus for this frame is the number of pins knocked down by the next roll.
   E. A Strike is when the player knocks down all 10 pins on his first try.
      The bonus for this frame is the number of pins knocked down by the next two rolls. 
   F. In the 10th frame, a player is allowed to throw an extra ball if she/he scores a Spare or a Strike.
      a. No more than three throws are allowed for the 10" frame.
      b. No bonus scores are granted for Strikes and Spares in 10th frame.
      c. If a player hits a Strike / Spare, 10 pins will be available again for the next throw within the 10th frame.
	  
3. Output: 
    The system displays the total calculted score after all rolls are entered.
	
4. Error Handling   
    • The system should validate input for the number of pins knocked down in each roll is between 0 and 10.
    • The program should handle cases where the user enters an invalid number of pins.
	  
5. Example Test case 

1-4,4,5,6,4,5,5,10,0,1,7,3,6,4,10,2,8,6
	2nd Frame:
	• Frame score is 9 (4+5)
	• Total score is 14 (9 frame score + 5 total score of frame 1)
	3rd Frame:
	• Frame score is 10 (Spare)
	• Total score is 29 (10 frame score + 14 total score of frame 2 + 5 bonus for next roll) 5th Frame:
    • Frame score is 10 (Strike)
    • Total score is 60 (10 frame score + 49 total score of frame 4 + 1 bonus for the next two rolls)
