#include "../header/Player.hpp"
#include <map>

using namespace std;

Player::Player(string name, bool color){
    this->name = name;
    blackWhite = color;
}

bool Player::getColor() {
    return blackWhite;
}

//bool Player::getInput() {

// }
int Player::makeMove(Board* board) {
    string input;
    char letter;
    int number;
    pair<int, int> start, dest;
    cout << "The player is white: " << getColor() << endl;
    cout << "Enter starting position (letter number): ";
    getline(cin, input);

    if (input == "resign") {
        cout << (getColor() ? "White" : "Black") << " player has resigned.\n";
        return 1;
    }

    istringstream input_stream(input);
    input_stream >> letter >> number;
    //cout << "we got here";
    start = make_pair(letterToNum[letter], numToNum[number]);
    //cout << "made the pair" << endl;
    //cout << start.second << ", " << start.first << endl;
    // Check if the soruce coordinates are on the board
    if (start.first < 0 || start.first > 7 || start.second < 0 || start.second > 7) {
            cout << "Invalid starting position.\n";
            return 2;
    }

    // Check if you are moving your own piece

    // Piece* piece = board->getPiece(start.second, start.first); 
    // cout << "This piece is: " << piece->getName() << endl;
    // cout << "The color of this piece is: " << piece->getColor() << endl; 
    // cout << "The 'x' coord is: " << piece->getXCoord() << endl;
    // cout << "The 'y' coord is: " << piece->getYCoord() << endl;

    // if(piece == nullptr){
    //     cout << "This is a nullptr" << endl;
    // }
    if(board->getPiece(start.second, start.first) == nullptr) {
        return false;
    }
    if(board->getPiece(start.second, start.first)->getColor() != this->getColor()) {
            cout << "Not a valid piece to move or no piece exists\n";
            return 2;
    }

    Piece* piece = board->getPiece(start.second, start.first); 

    // std::vector<std::pair<int, int>> possibleMoves = piece->getPossibleMoves(board);
    // // first in pair is col, second is row
    // for (const auto& move : possibleMoves) {
    //     std::cout << "(" << move.first << ", " << move.second << ")" << std::endl;
    // }

    cout << "Enter destination position (letter number): ";
    getline(cin, input);
    istringstream input_stream2(input);

    input_stream2 >> letter >> number;
    
    dest = make_pair(letterToNum[letter], numToNum[number]);
    //cout << "made the pair" << endl;

    // Check if the destination is on the board
    if (dest.first < 0 || dest.first > 7 || dest.second < 0 || dest.second > 7) {
            cout << "Invalid destination position.\n";
            return 2;
    }

    //cout << "got past validating on board" << endl;

    // Check if it's a valid move  (this is broken)
    //cout << "passing in row: " << dest.second << " and col: " << dest.first << endl;
    if(!(piece->move(dest.first, dest.second, board))) {
        cout << "Not a valid move" << endl;
        return 2;
    }
    //cout << "got past validatin" << endl;

    // Check for collision
    if(!board->isFree(dest.second, dest.first)){
        Piece* toBeRemoved = board->getPiece(dest.second, dest.first);
        addEliminated(toBeRemoved, board);
    }

    board->updateBoard(dest.second, dest.first, piece);
    
    // move successful
    //std::cout << "we did it reddit" << std::endl;
    return 0;
}

void Player::surrender() {
    
}

void Player::addEliminated(Piece* piece, Board* board) {
    eliminated.push_back(piece->getName());
    board->removePiece(piece);
    delete piece;
    piece = nullptr;
}

void Player::showEliminated() const{
    if (eliminated.empty()) {
            cout << "No pieces have been eliminated.\n";
            return;
        }
        
    cout << "Eliminated pieces: ";
    for (int x; x < eliminated.size(); x++) {
        cout << eliminated.at(x) << " ";
    }
    cout << "\n";
}

// ?? is this
Player::~Player() {
}