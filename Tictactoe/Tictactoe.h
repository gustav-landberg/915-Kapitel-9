
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>

//


class TicTacToe {

public:

	
	TicTacToe(bool toggleAI = true);


	void play();

	// Print the board.
	void printBoard();
	



	
private:


	enum PlayerType { NONE, PLAYER1, PLAYER2 };
	int board[3][3]; // 3x3 integer matrix
	int rowLength;

	// Allowed integer values: 1-9
	void place(PlayerType type, int n);

	
	int turnCount;
	

	bool playerTwoIsCPU;


	bool gameStarted;
	
	

	// Random placement.
	void processAI();


	int promptPlayer();


	// Return 3 if any line has been formed.
	bool checkIfWin(PlayerType player);

	bool hasOccupied(int n, TicTacToe::PlayerType player);

	// calls hasOccupied
	bool	   isOccupied(int n);

	
};



#endif