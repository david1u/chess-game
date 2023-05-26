#include "Player.hpp"
#include <map>

using namespace std;

void Player::makeMove() {
    char letter;
    int number;
    pair<int, int> start, dest;
    cout << "Enter starting position (letter number): ";
    cin >> letter >> number;
    start = make_pair(letterToNum[letter], number - 1);

    if (start.first < 0 || start.first > 7 || start.second < 0 || start.second > 7) {
            cout << "Invalid starting position.\n";
            return;
    }

    Piece* piece = board->getPiece(start.first, start.second); 

    cout << "Enter destination position (letter number): ";
    cin >> letter >> number;
    dest = make_pair(letterToNum[letter], number - 1);

    if (dest.first < 0 || dest.first > 7 || dest.second < 0 || dest.second > 7) {
            cout << "Invalid destination position.\n";
            return;
    }

    piece->move(dest.first, dest.second);


}

void Player::surrender() {

}

void Player::addEliminated(Piece* piece) {
    eliminated.push_back(piece);
}

void Player::showEliminated() const{
    if (eliminated.empty()) {
            cout << "No pieces have been eliminated.\n";
            return;
        }
        
    cout << "Eliminated pieces: ";
    for (const auto& piece : eliminated) {
        cout << piece->getName() << " ";
    }
    cout << "\n";
}

Player::~Player() {
    for (unsigned i = 0; i < eliminated.size(); i++) {
        delete eliminated.at(i);
    }
}