#include <iostream>
#include <iomanip>
#include "../header/Board.hpp"

void printBoard(const Board& board)
{
    const std::vector<std::vector<Piece*>>& chessBoard = board.getBoard();

    std::cout << "     A       B       C       D       E       F       G       H   \n";
    std::cout << "  ┏━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┓\n";

    for (int i = 0; i < 8; ++i)
    {
        std::cout << 8 - i << " ┃";
        for (int j = 0; j < 8; ++j)
        {
            Piece* piece = chessBoard[i][j];
            std::cout << " ";
            if (piece)
            {
                std::cout << std::setw(7) << piece->getName() << " ";
            }
            else
            {
                std::cout << std::setw(6) << " ";
            }
            std::cout << "│";
        }
        std::cout << "\n";

        if (i < 7)
        {
            std::cout << "  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤\n";
        }
    }

    std::cout << "  ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛\n";
}
