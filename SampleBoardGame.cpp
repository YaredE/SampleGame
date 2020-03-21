// SampleBoardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "Board.h"

#include <iostream>
#include <vector> 


static void printBoardDetails(Board & boardToPrint ) {

	std::cout << "====================================================================================== \n";
	std::cout <<  " The Given board looks like  \n";
	boardToPrint.print();
	std::cout << "   \n";
	std::string boardValidText;
	if (boardToPrint.isValidBoard()) {
		boardValidText = "Valid";
	}
	else {
		boardValidText = "invalid";
	}
	std::cout << "Checking if the board is valid  : " << boardValidText.c_str() << "  \n";
	std::cout << "Number of ships in the board is : " << boardToPrint.getShipCountOnBoard() << "\n";
	std::cout << "====================================================================================== \n";
}


int main()
{
	char DOT = '.';
	char PART = 'X';
	int TEST_SIZE = 4;

	char board[4][4] = { { DOT,PART, DOT, PART},{ DOT,PART, DOT, DOT}, { DOT,DOT, DOT, PART} };
	std::vector<std::vector<char>> boardData;
	
	for (int r = 0;  r < TEST_SIZE; r++) {
		std::vector<char> rowData;
		for (int co = 0; co < TEST_SIZE; co++) {
			rowData.push_back(board[r][co]);
		}
		boardData.push_back(rowData);
	}
	Board testBoard(boardData);
	printBoardDetails(testBoard);

	//Let us check for invalid board.
	char invalid_board[4][4] = { { DOT,PART, PART, PART},{ DOT,PART, DOT, DOT}, { DOT,DOT, DOT, PART} };
	std::vector<std::vector<char>> invalid_boardData;

	for (int r = 0; r < TEST_SIZE; r++) {
		std::vector<char> rowData;
		for (int co = 0; co < TEST_SIZE; co++) {
			rowData.push_back(invalid_board[r][co]);
		}
		invalid_boardData.push_back(rowData);
	}

	Board invalid_testBoard(invalid_boardData);
	printBoardDetails(invalid_testBoard);

}
