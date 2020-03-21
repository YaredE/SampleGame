#include "pch.h"
#include "Board.h"
#include <iostream>

using namespace std;


void printParts(std::vector <char> const &a) {
	std::cout << "The ship parts are : ";
	for (int inx = 0; inx < a.size(); inx++)
		std::cout << a.at(inx) << ' ';
}

Board::Board()
{
}

bool Board::isAShipParkedNext(int row, int col) {
	int nextRow = row + 1;
	int nextCol = col + 1;
	bool hasShipParkedToTheRight = false;
	if (nextRow < board.size()) {
		CELL currentCell = board.at(nextRow).at(col);
		hasShipParkedToTheRight = isShipOrPartOfShip(currentCell);
	}
	bool hasShipParkedBelow = false;
	if (nextCol < board.at(row).size()) {
		CELL currentCell = board.at(row).at(nextCol);
		hasShipParkedBelow = isShipOrPartOfShip(currentCell);
	}
	return hasShipParkedToTheRight && hasShipParkedBelow;
}

bool Board::isValidBoard() {
	//Board is valid if no two ships are next to each other.
	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board.at(0).size(); col++) {
			CELL currentCell = board.at(row).at(col);
			if (!isShipOrPartOfShip(currentCell)) {
				continue;
			}
			bool result = isAShipParkedNext(row, col);
			if (result) {
				return false;
			}
		}
	}
	return true;
}

Board::Board(std::vector<std::vector<char>> & gBoard)
{
	for (int row = 0; row < gBoard.size(); row++) {
		std::vector<CELL> rowData;
		for (int col = 0; col < gBoard.size(); col++) {
			CELL cell;
			cell.hasBeenVisted = false;
			cell.identifier = gBoard.at(row).at(col);
			rowData.push_back(cell);
		}
		board.push_back(rowData);
	}
}
bool Board::isShipOrPartOfShip(CELL & cell) {
	
	return cell.identifier == 'X';
}

int Board::getShipCountOnBoard() {
	int shipCount = 0;
	if (!isValidBoard()) {
		return shipCount;
	}
	for (int row = 0; row < board.size(); row++)
	{
		for (int col = 0; col < board.at(row).size(); col++) {
			CELL currentCell = board.at(row).at(col);
			if (!isShipOrPartOfShip(currentCell)) {
				continue;
			}
			std::vector<char> shipParts;
			int isValidDown = isCellValid(currentCell, DOWN, row, col, shipParts);
			if (isValidDown) {
				shipCount++;
			}
			shipParts.clear();
			int isValidRight = isCellValid(currentCell, RIGHT, row, col, shipParts);
			if (isValidRight) {
				shipCount++;
			}
		}
	}
	return shipCount;
}

bool Board::isCellValid(CELL & currentCell, TRAVERSE_DIRECTION direction, int row, int column, std::vector<char> & parts) {

	int nextRow = row + 1;
	int nextColumn = column + 1;


	if (direction == DOWN)
	{
		if (currentCell.hasBeenVisted) {
			return parts.empty() == false;
		}
		if (isShipOrPartOfShip(currentCell) ) {
			parts.push_back(currentCell.identifier); //How many cells is one ship made of?
		}
		currentCell.hasBeenVisted = true;
		board.at(row).at(column) = currentCell; //update
		if (board.at(row).size() <= nextRow)
		{// Edge of the board has been reached here.
			return parts.empty() == false;
		}

		CELL nextCell = board.at(nextRow).at(column);
		if ( !nextCell.hasBeenVisted ) {
			if (isShipOrPartOfShip(nextCell)) {
				return isCellValid(nextCell, DOWN, nextRow, column, parts);
			}
			else {
				nextCell.hasBeenVisted = true;
				return parts.empty() == false;
			}
		}
		return parts.empty() == false;
	}
	if (direction == RIGHT)
	{
		if (currentCell.hasBeenVisted) {
			return parts.empty() == false;
		}
		if (isShipOrPartOfShip(currentCell)) {
			parts.push_back(currentCell.identifier); //How many cells is one ship made of?
		}
		currentCell.hasBeenVisted = true;
		board.at(row).at(column) = currentCell; //update
		if (board.size() <= nextColumn)
		{// Edge of the board has been reached here.
			return parts.empty() == false;
		}

		CELL nextCell = board.at(row).at(nextColumn);
		if (!nextCell.hasBeenVisted) {
			if (isShipOrPartOfShip(nextCell)) {
				return isCellValid(nextCell, DOWN, nextRow, column, parts);
			}
			else {
				nextCell.hasBeenVisted = true;
				return parts.empty() == false;
			}
		}
		return parts.empty() == false;
	}
	return false;
}
void Board::print() {

	for (int row = 0; row < board.size(); row++) {
		std::vector<CELL> rowData;
		for (int col = 0; col < board.size(); col++) {
			std::cout << board.at(row).at(col).identifier << "  ";
		}
		std::cout  << "\n";
	}
}
