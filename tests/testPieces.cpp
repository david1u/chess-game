#include <gtest/gtest.h>
#include "../header/Piece.hpp"
#include "../header/Board.hpp"

TEST(allPiecesTest, init){
    Board *myBoard = new Board();
    Piece *blackPiece;
    Piece *whitePiece;
    for(int i = 0; i < 7; ++i){
        blackPiece = myBoard->getPiece(1,i);
        EXPECT_FALSE(blackPiece->getColor());
        EXPECT_EQ("♙", blackPiece->getName());

        whitePiece = myBoard->getPiece(6,i);
        EXPECT_TRUE(whitePiece->getColor());
        EXPECT_EQ("♟", whitePiece->getName());
    }
    blackPiece = myBoard->getPiece(0,0);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♖", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,1);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♘", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,2);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♗", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,3);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♕", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,4);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♔", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,5);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♗", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,6);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♘", blackPiece->getName());
    blackPiece = myBoard->getPiece(0,7);
    EXPECT_FALSE(blackPiece->getColor());
    EXPECT_EQ("♖", blackPiece->getName());

    whitePiece = myBoard->getPiece(7,0);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♜", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,1);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♞", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,2);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♝", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,3);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♛", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,4);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♚", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,5);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♝", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,6);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♞", whitePiece->getName());
    whitePiece = myBoard->getPiece(7,7);
    EXPECT_TRUE(whitePiece->getColor());
    EXPECT_EQ("♜", whitePiece->getName());

    delete myBoard;
    delete blackPiece;
    delete whitePiece;

}

TEST(movePawn, validMove2){
    Board *myBoard = new Board();
    Piece *testPiece = myBoard->getPiece(1,0);
    EXPECT_TRUE(testPiece->move(0, 3, *myBoard));

    //delete myBoard;
}

TEST(movePawn, validMove1){
    Board *myBoard = new Board();
    Piece *testPiece = myBoard->getPiece(1,0);
    EXPECT_TRUE(testPiece->move(0, 2, *myBoard));

    //delete myBoard;
}

TEST(movePawn, invalidMove1){
    Board *myBoard = new Board();
    Piece *testPiece = myBoard->getPiece(1,0);
    EXPECT_FALSE(testPiece->move(0, 6, *myBoard));

    //delete myBoard;
}

TEST(moveKnight, validMove){
    Board *myBoard = new Board();
    Piece *testPiece = myBoard->getPiece(0, 1);
    EXPECT_TRUE(testPiece->move(2, 2, *myBoard));
}

TEST(moveKnight, invalidMove){
    Board *myBoard = new Board();
    Piece *testPiece = myBoard->getPiece(0,1);
    EXPECT_FALSE(testPiece->move(2,1, *myBoard));
}

//TEST(movePawn, invalidMove){
//    
//}