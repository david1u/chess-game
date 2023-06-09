#include <gtest/gtest.h>
#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include "../header/DrawBoard.hpp"

TEST(allPiecesTest, init){
    Board myBoard;
    Piece *blackPiece;
    Piece *whitePiece;
    for(int i = 0; i < 7; ++i){
        blackPiece = myBoard.getPiece(1,i);
        EXPECT_FALSE(blackPiece->getColor());
        EXPECT_EQ("♙", blackPiece->getName());

        whitePiece = myBoard.getPiece(6,i);
        EXPECT_TRUE(whitePiece->getColor());
        EXPECT_EQ("♟", whitePiece->getName());
    }
    blackPiece = myBoard.getPiece(0,0);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♖", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,1);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♘", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,2);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♗", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,3);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♕", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,4);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♔", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,5);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♗", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,6);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♘", blackPiece->getName());
    blackPiece = myBoard.getPiece(0,7);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♖", blackPiece->getName());

    whitePiece = myBoard.getPiece(7,0);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♜", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,1);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♞", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,2);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♝", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,3);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♛", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,4);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♚", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,5);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♝", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,6);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♞", whitePiece->getName());
    whitePiece = myBoard.getPiece(7,7);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♜", whitePiece->getName());
}

TEST(PawnTest, ValidMoves) {
    // Create a board
    Board board;

    // Get the existing white and black pawns from the board
    Pawn* whitePawn = static_cast<Pawn*>(board.getPiece(6, 1));
    Pawn* blackPawn = static_cast<Pawn*>(board.getPiece(1, 1));

    // Assert valid move 1 up
    EXPECT_TRUE(whitePawn->move(1, 5, &board));

    // Assert valid move 2 up on first move
    EXPECT_TRUE(whitePawn->move(1, 4, &board));

    board.updateBoard(5, 0, blackPawn);

    // Assert diagonal capture
    EXPECT_TRUE(whitePawn->move(0, 5, &board));
}


TEST(PawnTest, InvalidMoves)
{
    // Create a board
    Board board;

    // Create a Pawn
    Pawn pawn(true, 1, 1);  // White Pawn at position (1, 1)

    // Test invalid moves for the Pawn
    EXPECT_FALSE(pawn.move(1, 1, &board));  // Invalid move (same position)
    EXPECT_FALSE(pawn.move(0, 2, &board));  // Invalid move (not forward)
    EXPECT_FALSE(pawn.move(2, 2, &board));  // Invalid move (not forward)

    // Test additional invalid moves
    EXPECT_FALSE(pawn.move(1, 0, &board));  // Invalid move (not forward)
    EXPECT_FALSE(pawn.move(1, 5, &board));  // Invalid move (not capturing diagonally)
    EXPECT_FALSE(pawn.move(1, 7, &board));  // Invalid move (out of bounds)
}



TEST(KnightTest, ValidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black knights from the board
    Knight* whiteKnight = static_cast<Knight*>(board.getPiece(7, 1));
    Knight* blackKnight = static_cast<Knight*>(board.getPiece(0, 6));

    // Move the white knight to a valid square
    board.updateBoard(0, 2, whiteKnight);

    // Assert that the move is valid
    EXPECT_TRUE(whiteKnight->move(3,2, &board));

    // Move the black knight to a valid square
    board.updateBoard(7, 6, blackKnight);

    // Assert that the move is valid
    EXPECT_TRUE(blackKnight->move(5, 5, &board));
}


TEST(KnightTest, InvalidMoves)
{
    // Create a board
    Board board;

    // Create a Knight
    Knight knight(true, 2, 2);  // White Knight at position (2, 2)

    // Test invalid moves for the Knight
    EXPECT_FALSE(knight.move(2, 2, &board));  // Invalid move (same position)
    EXPECT_FALSE(knight.move(1, 2, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(2, 3, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(0, 0, &board));  // Invalid move (out of bounds)

    // Test additional invalid moves
    EXPECT_FALSE(knight.move(1, 1, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(3, 3, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(4, 4, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(5, 2, &board));  // Invalid move (not an L-shape)
    EXPECT_FALSE(knight.move(2, 6, &board));  // Invalid move (not an L-shape)
}

TEST(BishopTest, ValidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black bishops from the board
    Bishop* whiteBishop = static_cast<Bishop*>(board.getPiece(7, 2));
    Bishop* blackBishop = static_cast<Bishop*>(board.getPiece(0, 5));

    // Move the black bishop to an empty square
    board.updateBoard(4, 4, blackBishop);


    // Assert valid moves for the white bishop
    Pawn* whitePawn = static_cast<Pawn*>(board.getPiece(6, 3));
    board.updateBoard(4, 4, whitePawn);
    EXPECT_TRUE(whiteBishop->move(4, 5, &board));  // Valid move: Diagonal move to
    EXPECT_TRUE(whiteBishop->move(3, 6, &board));  // Valid move: Diagonal move to

    // Move a white pawn to a square occupied by the black bishop
    board.updateBoard(4, 4, whitePawn);

    // Assert capturing move for the white bishop
    EXPECT_TRUE(whiteBishop->move(3, 6, &board));  // Valid move: Capture the black bishop
}

TEST(BishopTest, InvalidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black bishops from the board
    Bishop* whiteBishop = static_cast<Bishop*>(board.getPiece(7, 2));
    Bishop* blackBishop = static_cast<Bishop*>(board.getPiece(0, 5));

    // Move the black bishop to an empty square
    board.updateBoard(4, 4, blackBishop);

    // Assert invalid moves for the white bishop
    Pawn* whitePawn = static_cast<Pawn*>(board.getPiece(6, 3));
    board.updateBoard(4, 4, whitePawn);
    EXPECT_FALSE(whiteBishop->move(5, 5, &board));  // Invalid move: Blocked by white pawn
    EXPECT_FALSE(whiteBishop->move(6, 5, &board));  // Invalid move: Blocked by white pawn
    EXPECT_FALSE(whiteBishop->move(3, 7, &board));  // Invalid move: Out of bounds
    EXPECT_FALSE(whiteBishop->move(4, 4, &board));  // Invalid move: Same position

    // Move a black pawn to a square occupied by the white bishop
    Pawn* blackPawn = static_cast<Pawn*>(board.getPiece(1, 3));
    board.updateBoard(6, 5, blackPawn);

    // Assert invalid capturing move for the white bishop
    EXPECT_FALSE(whiteBishop->move(6, 5, &board));  // Invalid move: Cannot capture own piece
}

TEST(RookTest, ValidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black rooks from the board
    Rook* whiteRook = static_cast<Rook*>(board.getPiece(7, 0));

    // Move the black rook to an empty square

    // Assert valid moves for the white rook
    Pawn* whitePawn = static_cast<Pawn*>(board.getPiece(6, 0));
    board.updateBoard(3, 3, whitePawn);
    EXPECT_TRUE(whiteRook->move(0, 4, &board));  // Valid move: Vertical move 
    board.updateBoard(4, 0, whiteRook);
    EXPECT_TRUE(whiteRook->move(2, 4, &board));  // Valid move: Horizontal move 

    // Move a white pawn to a square occupied by the black rook
    board.updateBoard(3, 3, whitePawn);

    // Assert capturing move for the white rook
    EXPECT_TRUE(whiteRook->move(0, 1, &board));  // Valid move: Capture 
}

TEST(RookTest, InvalidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black rooks from the board
    Rook* whiteRook = static_cast<Rook*>(board.getPiece(7, 0));
    Rook* blackRook = static_cast<Rook*>(board.getPiece(0, 0));

    // Move the black rook to an empty square
    board.updateBoard(3, 3, blackRook);

    // Assert invalid moves for the white rook
    Pawn* whitePawn = static_cast<Pawn*>(board.getPiece(6, 0));
    board.updateBoard(3, 3, whitePawn);
    EXPECT_FALSE(whiteRook->move(2, 2, &board));  // Invalid move: Diagonal move
    EXPECT_FALSE(whiteRook->move(1, 4, &board));  // Invalid move: Not horizontal or vertical
    EXPECT_FALSE(whiteRook->move(7, 3, &board));  // Invalid move: Blocked by own piece

    // Move a white pawn to a square occupied by the black rook
    board.updateBoard(3, 3, whitePawn);

    // Assert invalid capturing move for the white rook
    EXPECT_FALSE(whiteRook->move(0, 0, &board));  // Invalid move: Capture own piece
}

TEST(QueenTest, ValidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black queens from the board
    Queen* blackQueen = static_cast<Queen*>(board.getPiece(0, 3));

    // Move the black queen to an empty square
    board.updateBoard(3, 3, blackQueen);

    // Assert move up
    EXPECT_TRUE(blackQueen->move(3, 2, &board));

    // Assert move down
    EXPECT_TRUE(blackQueen->move(3, 4, &board));

    // Assert move right
    EXPECT_TRUE(blackQueen->move(5, 3, &board));

    // Assert move left
    EXPECT_TRUE(blackQueen->move(1, 3, &board));
    
    // Assert capture
    EXPECT_TRUE(blackQueen->move(3, 6, &board));
}

TEST(QueenTest, InvalidMoves)
{
    // Create a board
    Board board;

    // Get the existing white and black queens from the board
    Queen* whiteQueen = static_cast<Queen*>(board.getPiece(7, 3));

    EXPECT_FALSE(whiteQueen->move(3, 7, &board));
    EXPECT_FALSE(whiteQueen->move(3, 6, &board));
    EXPECT_FALSE(whiteQueen->move(4, 7, &board));
    EXPECT_FALSE(whiteQueen->move(2, 7, &board));
}

TEST(KingTest, ValidMoves){
    Board board;

    King* whiteKing = static_cast<King*>(board.getPiece(7, 4));
    
    board.updateBoard(4, 4, whiteKing);

    Pawn* blackPawn = static_cast<Pawn*>(board.getPiece(1, 4));
    board.updateBoard(3, 4, blackPawn);

    EXPECT_TRUE(whiteKing->move(5, 4, &board));
    EXPECT_TRUE(whiteKing->move(3, 4, &board));
    EXPECT_TRUE(whiteKing->move(4, 3, &board));

    EXPECT_TRUE(whiteKing->move(3, 4, &board));
}

TEST(KingTest, InvalidMoves){
    Board board;

    King* whiteKing = static_cast<King*>(board.getPiece(7, 4));

    EXPECT_FALSE(whiteKing->move(3, 7, &board));
    
    board.updateBoard(4, 4, whiteKing);

    EXPECT_FALSE(whiteKing->move(4, 6, &board));
    Pawn* blackPawn = static_cast<Pawn*>(board.getPiece(1, 4));
    board.updateBoard(2, 4, blackPawn);

    EXPECT_FALSE(whiteKing->move(4, 2, &board));
}




















