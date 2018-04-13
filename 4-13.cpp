#include <iostream>
using namespace std;

char disaster();

int main() {

	while (1) {

		cout << "oh no " << disaster() << " are attacking!" << endl;
		system("pause");

	}
}

char disaster() {

	int prob = rand() % 100 + 1;
	if (prob <= 10)
		return 'f';
	if (prob >= 11 && prob <= 26)
		return 'r';
	if (prob <= 27 && prob <= 39)
		return 'a';
	if (prob <= 40 && prob <= 43)
		return 'm';
	else
		return 'n';
}