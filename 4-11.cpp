#include<iostream>
using namespace std;

int main() {
	int NumScores;
	cout << "give me the number of scores" << endl;
	cin >> NumScores;

	int biggest = 0;
	int temp;
	int sum = 0;

	for (int i = 0; i < NumScores; i++) {
		cout << "enter score:" << endl;
		cin >> temp;
		if (temp > biggest)
			biggest = temp;
		sum += temp;

	}

	cout << "the biggest score was " << biggest << endl;
	cout << "and the average was " << sum / NumScores << endl;
	system("pause");

}