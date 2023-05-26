#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#define BLACK_KING   "\u2654"   // ♔
#define BLACK_QUEEN  "\u2655"   // ♕
#define BLACK_ROOK   "\u2656"   // ♖
#define BLACK_BISHOP "\u2657"   // ♗
#define BLACK_KNIGHT "\u2658"   // ♘
#define BLACK_PAWN   "\u2659"   // ♙

#define WHITE_KING   "\u265A"   // ♚
#define WHITE_QUEEN  "\u265B"   // ♛
#define WHITE_ROOK   "\u265C"   // ♜
#define WHITE_BISHOP "\u265D"   // ♝
#define WHITE_KNIGHT "\u265E"   // ♞
#define WHITE_PAWN   "\u265F"   // ♟

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
      name = isWhite ? WHITE_PAWN : BLACK_PAWN;
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Rook : public Piece
{
public:
   Rook(bool isWhite)
   {
      name = isWhite ? WHITE_ROOK : BLACK_ROOK;
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Knight : public Piece
{
public:
   Knight(bool isWhite)
   {
      name = isWhite ? WHITE_KNIGHT : BLACK_KNIGHT;
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Bishop : public Piece
{
public:
   Bishop(bool isWhite)
   {
      name = isWhite ? WHITE_BISHOP : BLACK_BISHOP;
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class Queen : public Piece
{
public:
   Queen(bool isWhite)
   {
      name = isWhite ? WHITE_QUEEN : BLACK_QUEEN;
      white = isWhite;
   }
   bool move(int newX, int newY, Board &board) override;
};

class King : public Piece
{
public:
   King(bool isWhite)
   {
      name = isWhite ? WHITE_KING : BLACK_KING;
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