#include "Tictactoe.h"
#include <stdlib.h>
#include <time.h>
#include <stdexcept>



TicTacToe::TicTacToe(bool toggleAI, bool playerIsFirst)
{
	srand(time((NULL))); // generate seed at construction
	
	playerTwoIsCPU = toggleAI;

	turnCount = 0;

	// row length is 3.
	rowLength = 3;
	// Set all elements in array board to 0.
	for (int i = 0; i <= (rowLength * rowLength); i++) 
		place(TicTacToe::NONE, i); 
}

void TicTacToe::printBoard()
{
	
	std::cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << std::endl;
	std::cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << std::endl;
	std::cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << std::endl;

}

void TicTacToe::place(PlayerType player, int n) {
	

	if ((n >= 1) && (n <= 9)) {
		// because of how arrays work
		
		// prevent placing in taken slots


		n = n - 1;

		// From top to bottom, left to right.
		int verticalSteps = (n / rowLength);
		int horizontalSteps = (n % rowLength);




		if (board[verticalSteps][horizontalSteps] == 0 || player == NONE) { // Will prevent placement if slot already taken by other player. Will still allow reseting the slot to NONE.

			switch (player) {
			case NONE:
				board[verticalSteps][horizontalSteps] = 0;
				break;
			case PLAYER1:
				board[verticalSteps][horizontalSteps] = 1;
				break;
			case PLAYER2:
				board[verticalSteps][horizontalSteps] = 2;
				break;
			}

		}

	}


}

bool TicTacToe::checkIfWin(PlayerType player) {	
	// If all integers in any line is equivalent to that of the players number, the player has won.
	if (player == PLAYER1 || player == PLAYER2) {
		/*HORIZONTAL LINES*/
		if (((hasOccupied(1, player) && hasOccupied(2, player) && hasOccupied(3, player)) == true) ||
			((hasOccupied(4, player) && hasOccupied(5, player) && hasOccupied(6, player)) == true) ||
			((hasOccupied(7, player) && hasOccupied(8, player) && hasOccupied(9, player)) == true) ||
			/*VERTICAL LINES*/
			((hasOccupied(1, player) && hasOccupied(4, player) && hasOccupied(7, player)) == true) ||
			((hasOccupied(2, player) && hasOccupied(5, player) && hasOccupied(8, player)) == true) ||
			((hasOccupied(3, player) && hasOccupied(6, player) && hasOccupied(9, player)) == true) ||
			/*DIAGONAL LINES*/
			((hasOccupied(1, player) && hasOccupied(5, player) && hasOccupied(9, player)) == true) ||
			((hasOccupied(7, player) && hasOccupied(5, player) && hasOccupied(3, player)) == true)) {
			return true;
		}
		else{
			return false;
}
	}
	
	else
		throw std::invalid_argument(("Invalid PlayerType passed to TicTacToe::checkIfWin"));
}

inline bool TicTacToe::hasOccupied(int n, TicTacToe::PlayerType player)
{


	n = n - 1;
	int verticalSteps = (n / rowLength);
	int horizontalSteps = (n % rowLength);

	if (board[verticalSteps][horizontalSteps] == player) {
		return true;
	}
	else return false;

}

bool TicTacToe::isOccupied(int n)
{	// NULL = 0?
	n = n - 1;
	int verticalSteps = (n / rowLength);
	int horizontalSteps = (n % rowLength);

	if (board[verticalSteps][horizontalSteps] != 0) {
		return true;
	}
	else return false;
}




// Places a marker on a random square.
void TicTacToe::processAI()
{
	int move;
reroll:
	move = rand() % (1 + 9);

	if (isOccupied(move) == false) {
		place(PLAYER2, move);
		turnCount++;
	}
	else if (turnCount < (rowLength*rowLength)) // if not all moves taken
		goto reroll;
}

int TicTacToe::promptPlayer() 
{
	int choice;
	TicTacToe::printBoard();
	std::cout << "Select a square to place in (1-9): ";
	std::cin >> choice;
	std::cout << std::endl;
	turnCount++;
	return choice;
}

void TicTacToe::play() {

	bool running = true;

	std::cout << "Welcome to TicTacToe!" << std::endl;
	std::cout << "0 = empty, 1 = Player 1, 2 = Player 2" << std::endl;
	
	while (running && (turnCount < (rowLength * rowLength))) {// note: rowLength^2 <-> max turns possible
	

	
		place(TicTacToe::PLAYER1, promptPlayer()); 



		if (checkIfWin(TicTacToe::PLAYER1)) {
			std::cout << "Player 1 wins." << std::endl;
			running = false;
		}
		processAI();
		if (checkIfWin(TicTacToe::PLAYER2)) {
			std::cout << "Player 2 wins." << std::endl;
			running = false;
		}
	}

	printBoard();
}
