#include<fstream>
#include<iostream>
#include <ios>
#include <iomanip>

using namespace std;

int main() {
	ifstream nums;
	ofstream avg;

	double total = 0;
	int count = 0;

	nums.open("numbers.txt");
	avg.open("average.txt");

	if (!nums.is_open()) {
		cout << "Error: File does not exist.\n";
		return 0;
	}

	while (!nums.eof()) {
		int n;
		nums >> n;
		total += n;
		count++;
	}

	avg << fixed << setprecision(2) << showpoint << total / count;

	nums.close();
	avg.close();

	return 0;
}