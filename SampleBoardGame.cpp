// SampleBoardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "Board.h"

#include <iostream>
#include <vector> 

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
	testBoard.print();

	std::cout <<  "We have got : " << testBoard.getShipCountOnBoard() << " ships \n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
