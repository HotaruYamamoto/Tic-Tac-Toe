//Tic Tac Toe, by Jessi Stratton

//Include the libraries
#include <iostream>
#include <string>

//Useing standard namespace
using namespace std;

//Declare global variables
char board[9];

// decalre functions
void showBoard();
bool moveIsValid(int m);
int whoWon(); //Returns 0 is no one has won and 1 if player one has, 2 is player two has

void main()
{
	//Declare local variables
	string plrOneName;
	string plrTwoName;
	int whoseTurn = 1; // 1 is player one's turn, 2 is player two's turn.
	int move; // stores where the player wants to move
	int totalMoves = 0;

	// Assign values to the playing board
	board[0] = '0';
	board[1] = '1';
	board[2] = '2';
	board[3] = '3';
	board[4] = '4';
	board[5] = '5';
	board[6] = '6';
	board[7] = '7';
	board[8] = '8';

	// Get player names
	cout << "Player 1: Please enter your name." << endl;
	cin >> plrOneName;
	cout << "Player 2: Please enter your name." << endl;
	cin >> plrTwoName;

	while (whoWon() == 0 && totalMoves < 9)
	{

		//Do this until the player chooses a valid move
		do
		{


			//show the board
			showBoard();

			//Tell which player to move
			if (whoseTurn == 1)
			{
				cout << plrOneName << ": It's your turn." << endl;
			}
			else
			{
				cout << plrTwoName << ": It's your turn." << endl;
			}

			//get the move
			cout << "Enter the number of the spot where you'd like to place your move." << endl;
			cin >> move;
		} while (moveIsValid(move) != true);
		//Add 1 to total moves
		totalMoves++;

		// Change whose turn it is.
		switch (whoseTurn)
		{
		case (1):
		{
			board[move] = 'X';
			whoseTurn = 2;
			break;
		}
		case (2):
		{
			board[move] = 'O';
			whoseTurn = 1;
		}
		}
	}
	//show the board
	showBoard();

	if (whoWon() == 1)
	{
		cout << plrOneName << " has won the game !" << endl;
	}
	else if (whoWon() == 2)
	{
		cout << plrTwoName << " has won the game !" << endl;
	}
	else
	{
		cout << "It's a tie !" << endl;
	}

	system("PAUSE");
}
void showBoard()
{
	cout << endl;
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}
bool moveIsValid(int m)
{
	if (board[m] != 'X' && board[m] != 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int whoWon()
{
	if (board[0] == board[1] && board[1] == board[2])
	{
		if (board[0] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[3] == board[4] && board[4] == board[5])
	{
		if (board[3] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[6] == board[7] && board[7] == board[8])
	{
		if (board[6] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[0] == board[3] && board[3] == board[6])
	{
		if (board[0] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[1] == board[4] && board[4] == board[7])
	{
		if (board[1] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[2] == board[5] && board[5] == board[8])
	{
		if (board[2] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[0] == board[4] && board[4] == board[8])
	{
		if (board[0] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (board[2] == board[4] && board[4] == board[6])
	{
		if (board[2] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	return 0;
}