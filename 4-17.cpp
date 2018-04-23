#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in;
	ofstream o;
	o.open("Solved.txt");
	in.open("prob04.in.txt");
	unsigned long long loops;
	in >> loops;
	unsigned long long term;
	unsigned long long temp = 0;
	unsigned long long value = 1;
	unsigned long long value2;

	
	for (unsigned long long i = 0; i < loops; i++){
	in >> term;
	temp = 0;
	value = 1;
	value2 = 0;


	for (unsigned long long i = 0; i < term - 1; i++) {
		value2 = temp + value;
		temp = value;
		value = value2;
	}
	if (term == 0) {
		cout << "0" << endl;
		o << "1 = 0" << endl;
	}
		cout << temp << endl;
		o << term << " = " << temp << endl;

	}
	in.close();

}