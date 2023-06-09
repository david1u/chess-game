#include "../header/Board.hpp"
#include "../header/Piece.hpp"

Board::Board() {
    board.resize(8); // set board to have 8 rows

    // Initialize the first two rows with Black Pieces
    board[0].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    // Place the pieces in the starting position
    board[0][0] = new Rook(false, 0, 0); // Rook
    board[0][1] = new Knight(false, 1, 0); // Knight
    board[0][2] = new Bishop(false, 2, 0); // Bishop
    board[0][3] = new Queen(false, 3, 0); // Queen
    board[0][4] = new King(false, 4, 0); // King
    board[0][5] = new Bishop(false, 5, 0); // Bishop
    board[0][6] = new Knight(false, 6, 0); // Knight
    board[0][7] = new Rook(false, 7, 0); // Rook

    // Set pawns
    board[1].resize(8, nullptr);
    for (unsigned i = 0; i < 8; ++i) {
        board[1][i] = new Pawn(false, i, 1); // Pawn
    }


    // Initialize the last two rows with White Pieces
    // Set pawns
    board[6].resize(8, nullptr);
    for (unsigned i = 0; i < 8; ++i) {
        board[6][i] = new Pawn(true, i, 6); // Pawn
    }

    board[7].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    // Place the pieces in the starting position
    board[7][0] = new Rook(true, 0, 7); // Rook
    board[7][1] = new Knight(true, 1, 7); // Knight
    board[7][2] = new Bishop(true, 2, 7); // Bishop
    board[7][3] = new Queen(true, 3, 7); // Queen
    board[7][4] = new King(true, 4, 7); // King
    board[7][5] = new Bishop(true, 5, 7); // Bishop
    board[7][6] = new Knight(true, 6, 7); // Knight
    board[7][7] = new Rook(true, 7, 7); // Rook



    // Initialize the remaining rows with nullptr
    for (int row = 2; row < 6; row++) {
        board[row].resize(8, nullptr); // Resize each row to have 8 columns and initialize with nullptr
    }

}

std::vector<std::vector<Piece*>> Board::getBoard() const{
    return board;
}

Piece* Board::getPiece(int row, int col) const {
	return board[row][col];
}

bool Board::isFree(int row, int col) const {
	return getPiece(row, col) == nullptr;
}

void Board::updateBoard(int row, int col, Piece* piece){
    int oldX = piece->getXCoord();
    int oldY = piece->getYCoord();
    board[row][col] = piece;
    board[oldY][oldX] = nullptr;
    piece->setXCoord(col);
    piece->setYCoord(row);
    piece->addMoveCount();
}

void Board::removePiece(Piece* piece) {
    int col = piece->getXCoord();
    int row = piece->getYCoord();
    board[row][col] = nullptr;
}

void Board::addPiece(Piece* piece) {
    int col = piece->getXCoord();
    int row = piece->getYCoord();
    board[row][col] = piece;
}

// void Board::eliminatePiece(Piece* piece) {
//     int col = piece->getXCoord();
//     int row = piece->getYCoord();
//     eliminatedPieces.push_back(piece);
//     board[row][col] = nullptr;
// }

Board::~Board() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] != nullptr) {
                std::cout << "Deleting piece: " << board[row][col]->getName() << std::endl;
                delete board[row][col]; 
                board[row][col] = nullptr; // It's a good practice to set the pointer to nullptr after deleting
            }
        }
    }
}
