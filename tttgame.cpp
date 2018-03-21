#include <iostream>
#include "TicTacToeBoard.h"

using namespace std;

int main()
{
	TicTacToeBoard game;
	game.reset();
	do
	{
		int row;
		int col;
		game.displayBoard();
		cout<<game.whoseTurn()<<"'s turn.\n"
		    <<"Row: ";
		cin>>row;
		cout<<"Column: ";
		cin>>col;
		if( game.isEmpty(row,col) )
		{
			game.placeMark(game.whoseTurn(),row,col);
		}
	}while( game.checkWinner() == ' ' );
	
	switch(game.checkWinner())
	{
		case 'X':
			cout<<"X won!\n";
			break;
		case 'O':
			cout<<"O won!\n";
			break;
		default:
			cout<<"Tie game!\n";
			break;
	}
	return 0;
}