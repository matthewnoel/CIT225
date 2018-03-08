#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int maain() {
	ifstream in;
	ofstream out;
	string fName, lName;
	int age, numNames;

	in.open("info.txt");
	out.open("out.txt");

	if (!in.is_open()) {
		cout << "Error: File does not exist.\n";
		return 0;
	}

	in >> numNames;
	for (int i = 0; i < numNames; i++) {
		in >> fName;
		in >> lName;
		in >> age;

		out << fName << " " << lName << " is " << age << " years old.\n";
	}

	in.close();
	out.close();

	cout << "Success.\n";
	return 0;
}
