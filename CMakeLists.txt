cmake_minimum_required(VERSION 3.20)

project(final-project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")


ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(Piece
    header/Board.hpp
    src/Board.cpp
    header/Piece.hpp
    src/Piece.cpp
)
ADD_EXECUTABLE(testPieces
    src/Board.cpp 
    src/Piece.cpp 
    tests/testPieces.cpp
)

ADD_EXECUTABLE(chess
    src/main.cpp 
    src/Board.cpp 
    src/DrawBoard.cpp 
    src/Game.cpp 
    src/Menu.cpp 
    src/Piece.cpp 
    src/Player.cpp 
)

target_link_libraries(Piece gmock gtest gtest_main)
target_link_libraries(testPieces gmock gtest gtest_main)
target_link_libraries(chess gmock gtest gtest_main)