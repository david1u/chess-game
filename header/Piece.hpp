
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
#include <vector>
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
   int moveCount;

public:
   virtual bool move(int newX, int newY, Board &board) const = 0;
   std::vector<std::pair<int, int>> getPossibleMoves(Board &board);
   int getXCoord() const { return xCoord; }
   int getYCoord() const { return yCoord; }
   void setXCoord(int newX)  { xCoord = newX; }
   void setYCoord(int newY)  { yCoord = newY; }
   std::string getName() const { return name; }
   bool getColor() const { return white; }
   int getMoveCount() const {return moveCount; }
   void incMoveCount() {moveCount++; }
   //void addMoveCount() {moveCount++; }
};

class Pawn : public Piece
{
public:
   Pawn(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_PAWN : BLACK_PAWN;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
      moveCount = 0;
   }
   bool move(int newX, int newY, Board &board) const override;
   bool enPassant(int newX, int newY, Board &board) const;
   void pawnPromotion() ;
};

class Rook : public Piece
{
public:
   Rook(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_ROOK : BLACK_ROOK;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
   }
   bool move(int newX, int newY, Board &board) const override;
};

class Knight : public Piece
{
public:
   Knight(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_KNIGHT : BLACK_KNIGHT;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
   }
   bool move(int newX, int newY, Board &board) const override;
};

class Bishop : public Piece
{
public:
   Bishop(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_BISHOP : BLACK_BISHOP;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
   }
   bool move(int newX, int newY, Board &board) const override;
};

class Queen : public Piece
{
public:
   Queen(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_QUEEN : BLACK_QUEEN;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
   }
   bool move(int newX, int newY, Board &board) const override;
};

class King : public Piece
{
public:
   King(bool isWhite, int xCoord, int yCoord)
   {
      name = isWhite ? WHITE_KING : BLACK_KING;
      white = isWhite;
      this->xCoord = xCoord;
      this->yCoord = yCoord;
   }
   bool move(int newX, int newY, Board &board) const override;
   bool castle(int newX, int newY, Board &board) ;

};

#endif
