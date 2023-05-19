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
![betterDiagram](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/fb934304-745f-48bb-a077-ea604c96f53e)


### Screen Layouts
![Frame 4](https://user-images.githubusercontent.com/24498843/236995841-5f569cac-9a76-4ec1-8678-38aa2d3ec632.png)
> The menu previous to this one will ask the user if they desire to load a game or start a new game. This layout is of a simple menu that allows the user to decide if they will be facing a computer or another person in a new game. The menu will prompt for a name after either option is selected. 
![Frame 3](https://user-images.githubusercontent.com/24498843/236993878-49ebc3a0-7658-41ef-aeb9-70ebbdda1727.png)
> This layout is a mock-up of the chessboard in the context of a match between two players. No pieces are shown but will have icons representative of chess pieces. 

> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram!

![best diagram drawio](https://github.com/cs100/final-project-mchun078-mibra033-dlu046-akoth013/assets/129913826/f8fd3aa9-d909-41f5-aec8-b989c9a9c6ec)

 > **Menu Class**  
 > A menu class with a private string variable called menu and 2 public void functions called createGame() and displayMenu().

 > **Player Class**  
 > A player class with a private string variable called name and a private bool variable called BlackWhite, which is used for telling whether the player is the black or white pieces.

 > **Piece Class**  
 > An abstract piece class with 2 private bool variables called captured and BlackWhite used for telling whether the piece has been captured or not and whether the piece is black or white respectively. Also has 2 public void functions called captured() and movePiece()

 > **Pawn, King, Knight, Rook, Bishop, and Queen Classes**  
 > Derived classes from piece class with a private string variable called pieceType

 > **Square Class**  
 > A square class made up of 3 member variables: 2 bool variables called color and occupied for white and black squares and telling whether the square is occupied by a piece respectively, and a Piece variable called currPiece that tells what piece is on the tile. Contains 2 public void functions called setPiece(Piece newPiece) and removePiece(). 

 > **Board Class**  
 > A board class with 3 private member variables: a 2-D array of Square objects called chessBoard and 2 Piece arrays called eliminatedW and eliminatedB for keeping track of the pieces on each side that have been eliminated. Contains void initializeBoard() function, getPiece() function that takes a character and int and returns the piece at that coordinate, void pieceTakenB and pieceTakenW functions that take a Piece object and add it to the corresponding eliminated array, and a checkMove() function that takes 2 Piece parameters and returns a boolean. Composed of square objects.

 
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
 
