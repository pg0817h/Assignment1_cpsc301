#include <iostream>
using namespace std;
#include <fstream>

int main() {

	ofstream input("data.txt");

	input << "Maria" << " " << "Brown" <<'\0'<< 2100.90 << endl;
	input << "Jeffrey" << " " << "Jackson" <<'\0'<< 200.20 << endl;
	input << "Bernard" << " " << "Smith" <<'\0'<< 223.10 << endl;
	input << "Matthew" << " " << "Davenport" <<'\0'<< 1630.20 << endl;
	input << "Kimberly" << " " << "Macias" <<'\0'<< 19100.90 << endl;
	input << "Amber" << " " << "Daniels" << '\0'<< 2400.40 << endl;

}

