#ifndef Board_h
#define Board_h

#include <vector> 

// Used for traversing the board
enum TRAVERSE_DIRECTION { DOWN, RIGHT };

typedef struct Cell {
	char identifier;
	bool hasBeenVisted;
}CELL;


class Board
{
private:

public:
	Board();
	Board(std::vector<std::vector<char>> & gBoard);

	bool isValidBoard();
	int getShipCountOnBoard();
	void print();
private:
	std::vector<std::vector<CELL>> board;
	bool isCellValid(CELL & currentCell, TRAVERSE_DIRECTION direction, int row, int column, std::vector<char> & parts);
	bool isShipOrPartOfShip(CELL & cell);

};

#endif /* Board_h */