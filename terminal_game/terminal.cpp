#include <iostream>
#include "../communication/message.h"
#include "../communication/game_protocol.h"
#include <string>

int main() {
	//setup for simulate the board game
	Message m;

	//loop to simulate arduino loop
	bool kill = false;
	do {
		std::cout << (m.IsEmpty() ? "IT'S EMPTY" : "NOT EMPTY") << std::endl;

		std::cout << "Enter a SenderID and MSG -->";
		int sid, mg;
		std::cin >> sid >> mg;

		m.SetMsg(static_cast<CompID>(sid), static_cast<Protocol>(mg));

		std::cout << (m.IsEmpty() ? "IT'S EMPTY" : "NOT EMPTY") << std::endl;
		m.Clear();


		//ask to kill the game
		std::cout << "Do you want to kill the program (enter 1 to kill, 0 to not)";
		std::cin >> kill;
	} while(!kill);
	return 0;
}
