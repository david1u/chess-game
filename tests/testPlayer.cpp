#include <gtest/gtest.h>
#include "../header/Player.hpp"

// Mock Piece class for testing
class MockPiece : public Piece {
public:
    MOCK_METHOD0(getName, std::string());
};

TEST(PlayerTest, AddEliminated) {
    Player player;

    MockPiece *piece = new MockPiece();
    EXPECT_CALL(*piece, getName()).WillRepeatedly(::testing::Return("MockPiece"));

    player.addEliminated(piece);

    // TODO: Add some way to verify that the piece was correctly added to the player's list of eliminated pieces.
    // You might expose a "getEliminated()" method for this, or make the test a friend of Player class.
}

TEST(PlayerTest, ShowEliminated_NoEliminatedPieces) {
    Player player;
    testing::internal::CaptureStdout();

    player.showEliminated();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No pieces have been eliminated.\n");
}

TEST(PlayerTest, ShowEliminated_WithEliminatedPieces) {
    Player player;
    MockPiece *piece = new MockPiece();
    EXPECT_CALL(*piece, getName()).WillRepeatedly(::testing::Return("MockPiece"));

    player.addEliminated(piece);

    testing::internal::CaptureStdout();

    player.showEliminated();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Eliminated pieces: MockPiece\n");
}
