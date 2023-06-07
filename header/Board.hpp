#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>

class Piece;

class Board {
private:
	std::vector<std::vector<Piece*>> board;
public:
	Board(); // initialize default board

	std::vector<std::vector<Piece*>> getBoard() const;

	Piece* getPiece(int x, int y) const;

	bool isFree(int row, int col) const;

	void updateBoard(int newX, int newY, Piece* piece);

	~Board(); 
};



#endif