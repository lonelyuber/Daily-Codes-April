#include <iostream>
#include <Windows.h>

using namespace std;
char Songlist();

int main() {
	int i= 1;

	while (i != 0) {
		cout << "Press 0 to quit." << endl;
		cout << Songlist();
		cin >> i;
		switch (i) {
		case 1:
			PlaySound(TEXT("GetYou.wav"), NULL, SND_FILENAME);
			cout << "Daniel Ceasar - Get You" << endl;
			break;

		case 2:
			PlaySound(TEXT("Passionfruit.wav"), NULL, SND_FILENAME);
			cout << "Drake - Passionfruit" << endl;
			break;
		case 3:
			PlaySound(TEXT("Psycho.wav"), NULL, SND_FILENAME);
			cout << "Post Malone - Psycho" << endl;
			break;
		case 4:
			PlaySound(TEXT("BestPart.wav"), NULL, SND_FILENAME);
			cout << "H.E.R. & Daniel Ceasar - Best Part" << endl;
			break;
		}
	}
}

char Songlist()
{
	cout << endl;
	cout << "| Juke Box |" << endl;
	cout << "1 - Get You" << endl;
	cout << "2 - Passionfruit" << endl;
	cout << "3 - Psycho" << endl;
	cout << "4 - Best Part" << endl;
	return 0;
}