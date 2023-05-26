#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <string>
#include "Board.hpp"

class Board;

class Piece
{
   // xCoord will be the letters A through H
   // yCoord will be the numbers 1 through 8
protected:
   int xCoord;
   int yCoord;
   std::string name;
   bool white;

public:
   virtual bool move(int newX, int newY, Board &board) = 0;
   int getXCoord() const { return xCoord; }
   int getYCoord() const { return yCoord; }
   std::string getName() const { return name; }
   bool getColor() const { return white; }
};

class Pawn : public Piece
{
public:
   Pawn(bool isWhite)
   {
      name = isWhite ? '♟︎' : '♙';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Rook : public Piece
{
public:
   Rook(bool isWhite)
   {
      name = isWhite ? '♜' : '♖';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Knight : public Piece
{
public:
   Knight(bool isWhite)
   {
      name = isWhite ? '♞' : '♘';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Bishop : public Piece
{
public:
   Bishop(bool isWhite)
   {
      name = isWhite ? '♝' : '♗';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Queen : public Piece
{
public:
   Queen(bool isWhite)
   {
      name = isWhite ? '♛' : '♕';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class King : public Piece
{
public:
   King(bool isWhite)
   {
      name = isWhite ? '♚' : '♔';
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

// implementation just for testing
// bool Pawn::move(int newX, int newY, Board &board) { return false; }
// bool Rook::move(int newX, int newY, Board &board) { return false; }
// bool Knight::move(int newX, int newY, Board &board) { return false; }
// bool Bishop::move(int newX, int newY, Board &board) { return false; }
// bool Queen::move(int newX, int newY, Board &board) { return false; }
// bool King::move(int newX, int newY, Board &board) { return false; }

#endif