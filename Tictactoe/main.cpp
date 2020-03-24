#include "Tictactoe.h"

#include <iostream>

int main() {

	
	std::cout << "Game 1:" << std::endl;
	TicTacToe board1; // default to ai opponent on
	board1.play();
	

	std::cout << "Game 2:" << std::endl;
	TicTacToe board2(false);

	board2.play();
	

	return 0;
};
