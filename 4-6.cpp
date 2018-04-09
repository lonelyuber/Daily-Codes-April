#include <iostream>
#include <string>
using namespace std;

int main() {

	string userinput;

	char input = 'A';
	int room = 1;

	while (input != 'B') {
		switch (room) {

		case 1:
			cout << "You are in Room 1." << endl;
			cout << "You can go right by saying 'right'." << endl;
			getline(cin, userinput); {
				if (userinput.compare("right") == 0)
					room = 2;
			}
			break;

		case 2:
			cout << "You are in Room 2." << endl;
			cout << "You can go down by saying 'down'." << endl;
			cout << "Or go back by saying 'left'." << endl;
			getline(cin, userinput); {
				if (userinput.compare("down") == 0)
					room = 3;
				if (userinput.compare("left") == 0)
					room = 1;
			}
			break;

		case 3:
			cout << "You are in Room 3." << endl;
			cout << "You can go right by saying 'right'." << endl;
			cout << "Or go back by saying 'up'." << endl;
			getline(cin, userinput); {
				if (userinput.compare("right") == 0)
					room = 4;
				if (userinput.compare("up") == 0)
					room = 2;
			}
			break;

		case 4:
			cout << "You are in Room 4." << endl;
			cout << "You can go left by saying 'left'." << endl;
			getline(cin, userinput); {
				if (userinput.compare("left") == 0)
					room = 3;
			}
			break;

		}
	}
}