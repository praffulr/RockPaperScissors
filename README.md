# RockPaperScissors
This is a C++ based cli implementation of Rock-Paper-Scissors game. Any user can play with a randomly choosing computer through terminal.
The program takes in a player's name, and lets the user play any number of games (with an upper-limit of LONG_MAX).
The score is updated and shown at the end of each game, until the session ends.
Before ending the game session, the summary of the session is shown.

User Choice:
The user chooses his choice by typing an appropriate number in the terminal. 

Computer Choice:
Computer randomly chooses an option using a pseudorandom generator (implemented using standard cpp libraries).

Scoring:
Scoring rules of the game are based on the following:
  1. Rock smashes Scissors.
  2. Scissors cut Paper.
  3. Paper covers Rock.
 And, it's a tie when both players give the same choice.
 Winner gets a +1 in each round. Noone gets a point when it's a tie.
  
Session Result:
At the end of the session, total number of rounds played and the total round summary is displayed. It includes the user's final score, computer's final score and the number of games tied.

Testing Details:


Further Improvements:
-> Can implement a game engine which also stores the details of players, so that one's stats like win percentage, total games played, high score can be maintained.
-> A leaderboard can be possibly maintained based on the above stats.



