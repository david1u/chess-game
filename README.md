[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10882937&assignment_repo_type=AssignmentRepo)
# Chess Game
 
 Authors: [Joshua Harnett](https://github.com/Lietrix), [Mike Ibrahim](https://github.com/mibra0), [David Lu](https://github.com/david1u), [Matthew Chung](https://github.com/matthewc2003), [Ayush Kothule](https://github.com/akothule)

## Project Description
* Why is it important or interesting to us?
    * Because we enjoy playing chess, and creating a UI system will give us experience in a field we do not currently understand entirely.
* What languages/tools/technologies do we plan to use? (This list may change over the course of the project)                     
    * We plan on using C++, and WinForms.
* What will be the input/output of our project?
    * Input will be user commands, and outputs will be the UI.
 * What are the features that the project provides?
    * Saving, loading, undo moves, and a simple computer to play against. Alongside all the traditional rules of chess. The chess board will be displayed on a UI, and the user commands will be on a console.
## User Interface Specification
### Navigation Diagram



![Untitled Workspace](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/86d7ddd3-39d0-41ae-8424-cf8c7667726f)



### Screen Layouts

<img width="243" alt="Screen Shot 2023-05-25 at 11 32 58 PM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/7e3e573c-7a8a-4733-83aa-ead7a992505d">. 

> This menu is the first menu the player sees when they begin playing.  
> 

<img width="239" alt="Screen Shot 2023-05-25 at 11 40 54 PM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/5556a02f-f719-40c1-bff8-d1897a30a268">  


> The menu previous to this one will ask the user if they desire to start a new game or quit. This layout is of a simple menu that allows the user to decide if they will be facing a computer or another person in a new game.  
> 
![chessboard](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/de5d0404-b6b3-406a-b73d-4f03239cbdcf). 


> This layout is a mock-up of the chessboard in the context of a match between two players. 

<img width="228" alt="Screen Shot 2023-05-25 at 11 41 33 PM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/00826bfa-7222-40df-a365-39a05ae613a9">   

> This layout is for if a player wishes to surrender in the middle of a match.  
> 

<img width="234" alt="Screen Shot 2023-05-26 at 1 35 33 AM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/1a32deec-bd7c-4010-a284-ba6e626294b1">   

> This layout is to celebrate the winner of the chess match.  
> 


<img width="237" alt="Screen Shot 2023-05-26 at 1 36 01 AM" src="https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/c8cca6f3-3e01-414a-bbae-cd1af216a941">

> This layout is for when the user has finished their session.  
> 



## Class Diagram!

![FINALFINALUML](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/e4c9970d-8711-479c-bb62-646689100c2b)


 > **Menu Class**  
 > An abstract menu class with 2 private string variables called menuName. Also contains the public functions displayChoices(), quit(), and chessDisplay() to be inherited.  

> **Start Menu**  
> The first menu prompted to the user. It gives them two options, start playing or quit.  

> **Game Initiate Menu**  
> This menu right before the chess game begins. This menu prompts the user to input two player names for white and black.  

> **Surrender Menu**  
> This menu is shown to confirm if a player would like to forfeit a match.  

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
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
