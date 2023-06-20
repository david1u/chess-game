Authors: [Joshua Harnett](https://github.com/Lietrix), [Mike Ibrahim](https://github.com/mibra0), [David Lu](https://github.com/david1u), [Matthew Chung](https://github.com/matthewc2003), [Ayush Kothule](https://github.com/akothule)

## Project Description
* Why is it important or interesting to us?
    * Because we enjoy playing chess and it will be interesting to be on the developing side of this game that we are usually only playing.
* What languages/tools/technologies do we plan to use? (This list may change over the course of the project)                     
    * We plan on using C++.
* What will be the input/output of our project?
    * Input will be user commands, and outputs will be in the terminal.
 * What are the features that the project provides?
    * This is a very traditional game of chess with some added features such as undoing a move. Both the chess board and the user commands will be done through terminal.
## User Interface Specification
### Navigation Diagram


![Untitled Workspace (2)](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/790dd91b-42ba-4e88-bf6b-67143ee62766)


### Screen Layouts

<!-- <img width="243" alt="Screen Shot 2023-05-25 at 11 32 58 PM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/7e3e573c-7a8a-4733-83aa-ead7a992505d">. -->

![image](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/02167cb5-8935-400c-a87f-b9b905628777)

> This menu is the first menu the player sees when they begin playing.  
> 

<!-- <img width="239" alt="Screen Shot 2023-05-25 at 11 40 54 PM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/5556a02f-f719-40c1-bff8-d1897a30a268">  -->
![image](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/36e1bba2-fa25-4708-9476-84cfe9020e00)


> The menu previous to this one will ask the user if they desire to start a new game or quit. This layout is of a simple menu that allows the user to decide if they will be facing a computer or another person in a new game.  
> 

<!-- ![chessboard](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/de5d0404-b6b3-406a-b73d-4f03239cbdcf). -->
![image](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/d64ee667-7b88-4f0d-a896-bda932c42c63)


> This layout is a mock-up of the chessboard in the context of a match between two players. 

<!-- <img width="234" alt="Screen Shot 2023-05-26 at 1 35 33 AM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/1a32deec-bd7c-4010-a284-ba6e626294b1">   -->
<img width="767" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/cb966a27-de6b-4972-bde8-de1165fd824d">

> This layout is to celebrate the winner of the chess match.  
> 



## Class Diagram!

![FINALFINALUML](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/e4c9970d-8711-479c-bb62-646689100c2b)


 > **Menu Class**  
 > An abstract menu class with 2 private string variables called menuName. Also contains the public functions displayChoices(), quit(), and chessDisplay() to be inherited.  

> **Start Menu**  
> The first menu prompted to the user. It gives them two options, start playing or quit.  

> **Game Initiate Menu**  
> This menu right before the chess game begins. This menu prompts the user to input two player names for white and black.  

> **Results Menu**  
> This menu prints out the winner of the chess match and shows the pieces captured by both sides.  

 > **Player Class**  
 > The player class contains a private string for name, a private boolean for isWhite, a private vector of strings to store the eliminated pieces, and lastly, two maps to parse the conventional chess grid format into a useable coordinate for our chess board. The class also has setters and getters for their color and eliminated piece vectors, constructors, destructors, a surrender function, and a makeMove function that begins the move sequence.  

> **Game Class**  
> The game class organizes all the other classes to create a functioning game of chess. It holds a board pointer, two vectors of Piece pointers for both black and white pieces, two player pointers, and a menu pointer. It also has a constructor, a destructor, getters and setters for menu, board, and players, as well as check functions for check and checkmate.  

 > **Piece Class**   
 > This class contains private variables for the x and y coordinate of the piece, the name of the piece, the color of the piece, and the number of moves the piece has made. It also contains another move function, a getPossibleMovesFunction and setters/getters for each private variable.  

 > **Pawn, King, Knight, Rook, Bishop, and Queen Classes**  
 > Derived classes from piece class with a public move function for each specific piece. The pawn class also includes functions like enPassant() and pawnPromotion(). The king class has an extra castle() function.  

> **DrawBoard Class**  
> This class possesses one function to print out the board.  

 > **Board Class**  
 > The board class contains a single private variable, a 2-D vector of Piece pointers. Its public functions include a getBoard function that returns the whole board, a getPiece function that returns the piece at a certain coordinate, a isFree function that tells if a certain space is empty, an updateBoard function, and a removePiece function.  
 
 > **UPDATES** 
 > In this class diagram update we applied the single responsibility principle while also reinforcing the interface segregation principle. First of all, we decided to remove the display board function and display menu function from the board class and the menu class respectively. We did this to avoid storing data and displaying to terminal in the same class. Second, we added the unique features that some chess pieces posses, ie. en passant, castling. This falls under interface segregation principle because we are not implementing functions that are never used in other chess pieces.

> **UPDATES 2.0**  
> In this new class diagram, we scrapped the square class since we decided it violated the dependency inversion principle. We believed it was a violation because it was making the piece class (low level module) rely on the square class (low level module) instead of an abstract. We also made the menu class an abstract class, with various different menus as subclasses, to help enforce the open-close principle. Now we can add menus by creating new classes instead of editing the menu class itself. Lastly, the drawBoard class was created to enforce the single responsibility principle. Now we do not have a board class that is storing data while also outputting to terminal.
 
 ## Screenshots
 > <img width="315" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/fbaac98f-2fec-4325-8267-4e160c2e77cc">  
 > <img width="302" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/6da71f8d-cc20-42ff-862c-9c21c12f335b">  
<img width="498" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/47431e24-ee13-4314-a924-0f2838eb6af5">    
<img width="502" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/0696749e-8f41-493d-a2ee-2d8bb71ef519">   


 ## Installation/Usage
 > To install the game you must first clone the repository recursively
 > git clone https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013.git --recursive
 > 
 > Make sure to navigate to the final project folder before running the following commands
 > Afterwards, you can run cmake .
 > 
 > ```cmake .```
 > 
 > Then run the make command
 > 
 > ```make```
 > 
 > The programs are now compiled in the bin folder, to run the chess program to play the game
 > 
 > ```bin/chess```
 > 
 ## Testing
 > For our project, we used the google testing and mocking framework to validate/test our code. We wrote unit tests for the menu class, player class, and piece class. We also used valgrind to check for memory errors and leaks. Here is an example of our unit tests and a screenshot of the test executable results:  
 
<img width="656" alt="image" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/b8621945-efbc-4e50-8659-9bbfd113568a">. 
![image](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/aee6ec2c-a173-4ed2-918a-1b7614519f06)
 
