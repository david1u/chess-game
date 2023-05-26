#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Piece.hpp"
#include <vector>

class Board {
private:
	std::vector<std::vector<Piece*>> board;
public:
	Board(); // initialize default board

	std::vector<std::vector<Piece*>> getBoard() const;

	Piece* getPiece(int x, int y) const;

	bool isFree(int row, int col) const;

	void updateBoard(int newX, int newY, Piece* piece);
};

Board::Board() {
    board.resize(8); // set board to have 8 rows

    // Initialize the first two rows with lowercase pieces
    board[0].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    // Place the pieces in the starting position
    board[0][0] = new Rook(false); // Rook
    board[0][1] = new Knight(false); // Knight
    board[0][2] = new Bishop(false); // Bishop
    board[0][3] = new Queen(false); // Queen
    board[0][4] = new King(false); // King
    board[0][5] = new Bishop(false); // Bishop
    board[0][6] = new Knight(false); // Knight
    board[0][7] = new Rook(false); // Rook

    // Set pawns
    board[1].resize(8, nullptr);
    for (unsigned i = 0; i < 8; ++i) {
        board[1][i] = new Pawn(false); // Pawn
    }

    // Set pawns
    board[6].resize(8, nullptr);
    for (unsigned i = 0; i < 8; ++i) {
        board[6][i] = new Pawn(true); // Pawn
    }

    board[7].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    // Place the pieces in the starting position
    board[7][0] = new Rook(true); // Rook
    board[7][1] = new Knight(true); // Knight
    board[7][2] = new Bishop(true); // Bishop
    board[7][3] = new Queen(true); // Queen
    board[7][4] = new King(true); // King
    board[7][5] = new Bishop(true); // Bishop
    board[7][6] = new Knight(true); // Knight
    board[7][7] = new Rook(true); // Rook



    // Initialize the remaining rows with nullptr
    for (int row = 2; row < 6; row++) {
        board[row].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    }
}

bool Board::isFree(int row, int col) const {
	return getPiece(row, col) == nullptr;
}

Piece* Board::getPiece(int x, int y) const {
	return board[x][y];
}

#endif