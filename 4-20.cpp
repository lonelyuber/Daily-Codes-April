#include<iostream>
#include<fstream>
#include<string>
#include<vector>//arrays that can grow and shrink
using namespace std;

int main() {

	vector <string> words;
	vector <string> ::iterator iter;
	vector <char> ::iterator charIter;


	int NumLines;
	string line;


	ifstream myFile; //get ready to get a file
	myFile.open("ICAO.txt"); //opens the file
	myFile >> NumLines;
	cout << "the number of lines is" << NumLines << endl; //optional testing
	while (getline(myFile, line)) //read the rest of it!
	{
		cout << line << '\n';
		words.push_back(line);
	}
	myFile.close();



	for (iter = words.begin(); iter != words.end(); iter++) {
		cout << *iter << endl;	//print out contents of vector for testing purposes

								//load each word from the word vector into its own char vector
		string s(*iter);
		vector<char> v(s.begin(), s.end());
		for (charIter = v.begin(); charIter != v.end(); charIter++) {
	 //eventually chage to write to file!
			if (*charIter == 'a')
				cout << "alpha!" << endl;
			if (*charIter == 'b')
				cout << "bravo!" << endl;
			if (*charIter == 'c')
				cout << "charlie!" << endl;
			if (*charIter == 'd')
				cout << "delta!" << endl;
			if (*charIter == 'e')
				cout << "echo!" << endl;
			if (*charIter == 'f')
				cout << "foxtrot!" << endl;
			if (*charIter == 'g')
				cout << "golf!" << endl;
			if (*charIter == 'h')
				cout << "hotel!" << endl;
			if (*charIter == 'i')
				cout << "india!" << endl;
			if (*charIter == 'j')
				cout << "juliet!" << endl;
			if (*charIter == 'k')
				cout << "kilo!" << endl;
			if (*charIter == 'l')
				cout << "lima!" << endl;
			if (*charIter == 'm')
				cout << "mike!" << endl;
			if (*charIter == 'n')
				cout << "November" << endl;
			if (*charIter == 'o')
				cout << "oscar" << endl;
			if (*charIter == 'p')
				cout << "papa" << endl;
			if (*charIter == 'q')
				cout << "quebec" << endl;
			if (*charIter == 'r')
				cout << "romeo" << endl;
			if (*charIter == 's')
				cout << "sierra" << endl;
			if (*charIter == 't')
				cout << "tango" << endl;
			if (*charIter == 'u')
				cout << "uniform" << endl;
			if (*charIter == 'v')
				cout << "victor" << endl;
			if (*charIter == 'w')
				cout << "whiskey" << endl;
			if (*charIter == 'x')
				cout << "xray" << endl;
			if (*charIter == 'y')
				cout << "yankee" << endl;
			if (*charIter == 'z')
				cout << "zulu" << endl;
		}
	}
}