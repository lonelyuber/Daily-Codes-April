#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int i = rand() % 10 + 1;
	int j = rand() % 10 + 1;

	cout << "This is Pink Toe." << endl;
	system("pause");


	string color[10] = { "Red", "Orange", "Yellow", "Blue", "Green", "Purple", "Pink", "White", "Black", "Brown" };

	string bodypart[10] = { "Feet", "Elbow", "Stomach", "Forehead", "Nose", "Finger", "Ear", "Knee", "Chest", "Lips" };

	// call out
	cout << color[i] << " " << bodypart[j] << endl;

}