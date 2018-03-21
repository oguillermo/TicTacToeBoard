#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

#include <vector>
#include <string>

typedef std::vector<std::vector<char> > board;

class TicTacToeBoard
{
	private:
		board grid;
		char turn;
		char horizontalWinner();
		char verticalWinner();
		char diagonalWinner();
		char getMark(int,int);
		bool inBounds(int,int);
	public:
		TicTacToeBoard();
		void displayBoard();
		char checkWinner();
		bool isEmpty(int,int);
		void placeMark(char,int,int);
		void reset();
		char whoseTurn();
};

#include "TicTacToeBoard.cpp"
#endif