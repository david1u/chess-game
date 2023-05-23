#include "Player.hpp"

using namespace std;

void Player::makeMove() {

}

void Player::surrender() {

}

void Player::addEliminated(Piece* piece) {
    eliminated.push_back(piece);
}

Player::~Player() {
    for (unsigned i = 0; i < eliminated.size(); i++) {
        delete eliminated.at(i);
    }
}