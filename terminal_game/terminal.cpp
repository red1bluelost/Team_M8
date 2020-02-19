#include <iostream>

int main() {
	//setup for simulate the board game
	

	//loop to simulate arduino loop
	bool kill = false;
	do {




		//ask to kill the game
		std::cout << "Do you want to kill the program (enter 1 to kill, 0 to not)";
		std::cin >> kill;
	} while(!kill);
	return 0;
}
