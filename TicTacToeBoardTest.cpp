/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <iostream>
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
TicTacToeBoardTest();
SetUp();

TearDown();
~TicTacToeBoardTest();
ASSERT_TRUE(true);
}
*/
TEST(TicTacToeBoardTest, blankBoard)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.getWinner();
  TearDown();
	ASSERT_TRUE(temp == Invalid);
}

TEST(TicTacToeBoardTest, toggleTurn)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.toggleTurn();
  TearDown();
	ASSERT_TRUE(temp == X);
}

TEST(TicTacToeBoardTest, placePieceCorrect)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
  TearDown();
	ASSERT_TRUE(temp == X);
}

TEST(TicTacToeBoardTest, placePieceInvalidLocation)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(-1,0);
  TearDown();
	ASSERT_TRUE(temp == Invalid);
}

TEST(TicTacToeBoardTest, placePieceAlreadyPlaced)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
	temp = board.placePiece(0,0);
  TearDown();
	ASSERT_TRUE(temp == Invalid);
}

TEST(TicTacToeBoardTest, WinUp)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
	temp = board.placePiece(0,1);
	temp = board.placePiece(1,0);
	temp = board.placePiece(0,2);
	temp = board.placePiece(2,0);
	temp = board.getWinner();
  TearDown();
	ASSERT_TRUE(temp == X);
}

TEST(TicTacToeBoardTest, WinSidewise)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
	temp = board.placePiece(1,0);
	temp = board.placePiece(0,1);
	temp = board.placePiece(1,1);
	temp = board.placePiece(0,2);
	temp = board.getWinner();
  TearDown();
	ASSERT_TRUE(temp == X);
}

TEST(TicTacToeBoardTest, WinDiag)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
	temp = board.placePiece(1,0);
	temp = board.placePiece(1,1);
	temp = board.placePiece(2,1);
	temp = board.placePiece(2,2);
	temp = board.getWinner();
  TearDown();
	ASSERT_TRUE(temp == X);
}

TEST(TicTacToeBoardTest, GetPiece)
{
  SetUp();
  TicTacToeBoard board;
  Piece temp = board.placePiece(0,0);
	temp = board.getPiece(0,0);
  TearDown();
	ASSERT_TRUE(temp == X);
}
