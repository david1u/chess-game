CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(final-project)


ADD_EXECUTABLE(chess
    src/main.cpp 
    src/Board.cpp 
    src/DrawBoard.cpp 
    src/Game.cpp 
    src/Menu.cpp 
    src/Piece.cpp 
    src/Player.cpp 
)

TARGET_LINK_LIBRARIES(chess PUBLIC "${PROJECT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/header")

