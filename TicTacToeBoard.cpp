char TicTacToeBoard::whoseTurn()
{
	return turn;
}

bool TicTacToeBoard::inBounds(int row, int col)
{
	return row < grid.size() && col < grid[0].size() && row >= 0 && col >= 0;
}

bool TicTacToeBoard::isEmpty(int row, int col)
{
  	char mark; 
  	if( inBounds(row,col) )
  	{
	  	mark = grid[row][col];
	  
		if(mark == 'X' || mark== 'O')
		{
		    return false;
		}
		else
		{
		    return true;
		}
	}
	else
	{
		return false;
	}
}

void TicTacToeBoard::placeMark(char mark, int row, int col)
{
	if( inBounds(row,col) && isEmpty(row,col) )
	{
		grid[row][col] = mark;
	}
	else
	{
		std::cout<<row<<","<<col<<" is invalid.\n";
	}

	if( turn=='X' )
	{
		turn='O';
	}
	else
	{
		turn='X';
	}
}

TicTacToeBoard::TicTacToeBoard()
{
	grid.resize(3);
	for(int row=0; row<grid.size(); row++)
	{
		grid[row].resize(3);
	}
	reset();
}

void TicTacToeBoard::reset()
{
	for(int r=0; r<grid.size(); r++)
	{
		for(int c=0; c<grid[r].size(); c++)
		{
			grid[r][c] = ' ';
		}
	}
	turn = 'X';
}

char TicTacToeBoard::getMark(int row, int col)
{
	char mark = '\0';  //'\0' is "no character"
	if( inBounds(row,col) )
  	{
  		mark = grid[row][col];
  	}
  	return mark;
}

char TicTacToeBoard::checkWinner()
{
	if( horizontalWinner() != ' ' )
	{
		return horizontalWinner();
	}
	else if( verticalWinner() != ' ' )
	{
		return verticalWinner();
	}
	else if( diagonalWinner() != ' ' )
	{
		return diagonalWinner();
	}
	else
	{
		for(int r=0; r<grid.size(); r++)
		{
			for(int c=0; c<grid[r].size(); c++)
			{
				if( isEmpty(r,c) )
				{
					return ' ';
				}
			}
		}
		return 'T'; //tie game if no empty spaces and no winners
	}
	
}
char TicTacToeBoard::horizontalWinner()
{
	for (int i = 0; i < grid.size(); i++) 
	{
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) 
		{
			return grid[i][0];
		}
	}
	return ' ';
}

char TicTacToeBoard::verticalWinner()
{
	for (int i = 0; i < grid[0].size(); i++) 
	{
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) 
		{
			return grid[0][i];
		}
	}
	return ' ';
}

char TicTacToeBoard::diagonalWinner()
{
	if( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] )
	{
		return grid[0][0];
	}
	else if( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] )
	{
		return grid[0][2];
	}
	else
	{
		return ' ';
	}
}



void TicTacToeBoard::displayBoard()
{
	for(int row=0; row<grid.size(); row++)
	{
		for(int col=0; col<grid[0].size(); col++){
			std::cout<<grid[row][col]<< "||";
		}
		std::cout<<std::endl;
	}
}