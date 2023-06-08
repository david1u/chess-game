#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>
#include <iostream>

class Piece;

class Board {
private:
	std::vector<std::vector<Piece*>> board;
public:
	Board(); // initialize default board

	std::vector<std::vector<Piece*>> getBoard() const;

	Piece* getPiece(int row, int col) const;

	bool isFree(int row, int col) const;

	void updateBoard(int row, int col, Piece* piece);

	~Board(); 
};



#endif