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

bool Player::makeMove(Board* board) {
    char letter;
    int number;
    pair<int, int> start, dest;
    cout << "Enter starting position (letter number): ";
    cin >> letter >> number;
    start = make_pair(letterToNum[letter], number - 1);

    // Check if the soruce coordinates are on the board
    if (start.first < 0 || start.first > 7 || start.second < 0 || start.second > 7) {
            cout << "Invalid starting position.\n";
            return false;
    }

    // Check if you are moving your own piece

    if(board->getPiece(start.first, start.second)->getColor() != this->getColor()) {
            cout << "Not a valid piece to move or no piece exists\n";
            return false;
    }

    Piece* piece = board->getPiece(start.first, start.second); 

    cout << "Enter destination position (letter number): ";
    cin >> letter >> number;
    dest = make_pair(letterToNum[letter], number - 1);

    // Check if the destination is on the board
    if (dest.first < 0 || dest.first > 7 || dest.second < 0 || dest.second > 7) {
            cout << "Invalid destination position.\n";
            return false;
    }

    // Check if it's a valid move 
    if(!(piece->move(dest.first, dest.second, board))) {
        return false;
    }

    // Check for collision
    if(!board->isFree(dest.first, dest.second)){
        Piece* toBeRemoved = board->getPiece(dest.first, dest.second);
        addEliminated(toBeRemoved);
    }

    board->updateBoard(dest.first, dest.second, piece);
    
    // move successful
    return true;
}

void Player::surrender() {
    
}

void Player::addEliminated(Piece* piece) {
    eliminated.push_back(piece->getName());
    delete piece;
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