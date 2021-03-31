/* main_world.h
 * TBA's Main World [earth]
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void sell(string item2sell) {
	int amounttosell;
	if (item2sell == "apple") {
		int apples2sell;
		
        	ifstream moneyapplefile("money.txt");
       		 string moneyapplecount( (istreambuf_iterator<char>(moneyapplefile) ),
	        (istreambuf_iterator<char>()    ) );

                ifstream applemoneyfile("apples.txt");
                 string applemoneycount( (istreambuf_iterator<char>(applemoneyfile) ),
                (istreambuf_iterator<char>()    ) );


		cout << "How many apples would you like to sell (1 apple = $1)?\n";
		cin >> apples2sell;

		int applesbeforesell = stoi(applemoneycount);
		int moneybeforesell = stoi(moneyapplecount);

		int applesaftersell = applesbeforesell - apples2sell;
		int moneyaftersell = moneybeforesell + apples2sell;
		
		ofstream moneysellfile("money.txt");
        	moneysellfile << moneyaftersell;
        	moneysellfile.close();

		ofstream applesellfile("apples.txt");
		applesellfile << applesaftersell;
		applesellfile.close();

	
	}

}

void world() {
	string cmdinput; // For Command-Input interpretation
	while (1) {
	// Read inventory files
	ifstream moneyfile("money.txt");
        string moneycount( (istreambuf_iterator<char>(moneyfile) ),
        (istreambuf_iterator<char>()    ) );
	ifstream applefile("apples.txt");
        string applecount( (istreambuf_iterator<char>(applefile) ),
        (istreambuf_iterator<char>()    ) );

	cout << "planet:earth. money:" << moneycount  << "> ";
	cin >> cmdinput;

        if (cmdinput == "help") {
                cout << "COMMAND LIST\nhelp - Displays this list of commands\ninv - Shows the items in your inventory; e.g. money\nsell - Sell your apples for money";
        } else if (cmdinput == "inv") {
		cout << "== Inventory Contains ==\n";
		cout << "Money: " << moneycount << "\n";
		cout << "Apples: " << applecount << "\n";

        } else if (cmdinput == "sell") {
		sell("apple");
	} else {
		cout << "error: fatal: '" << cmdinput << "' is not a command.\n";
	}

	}

}
