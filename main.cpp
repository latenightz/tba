/* main.cpp
 * TBA game launcher
*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "main_world.h"

using namespace std;

void newgame() {
	string username;
	cout << "Your username: ";
	cin >> username;
	// Create data files
	ofstream usernamefile("usrname.txt");
	usernamefile << username;
	usernamefile.close();

	ofstream applesfile("apples.txt");
	applesfile << "10";
	applesfile.close();

	ofstream moneyfile("money.txt");
	moneyfile << "5";
	moneyfile.close();

	world();
}

void loadgame() {
	world();
}

int main() {
	// Splash Text
	srand ( time(NULL) );
	const string arrayNum[4] = {"Y2K Compliant!", "Github.com/latenightz/tba !!", "woah how did I get here?", "ever play pong?"};
	int RandIndex = rand() % 4;
	cout << arrayNum[RandIndex] << "\n";
	
	string gamechoice;
	string version = "pre-alpha 1";
	cout << "TBA " << version << "\nType 1 to start a new savegame; Type 2 to load a savegame.\n";
	cin >> gamechoice;

	if (gamechoice == "1") {
		cout << "Creating a new savegame...\n";
		newgame();
	} else if (gamechoice == "2") {
		cout << "Loading your savegame...\n";
		loadgame();
	}
}
