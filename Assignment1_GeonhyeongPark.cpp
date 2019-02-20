#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;


struct PERSON {

	char Name[20];
	float Balance;

};

void Display(PERSON *a, int &arraySize) {

	cout << "  Name" << "	  " << "Balance" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << a[i].Name << " ";
		cout << a[i].Balance;
		cout << endl;
	}


}



void FindRichest(PERSON *a, int &arraySize) {
	string result;
	float max = a[0].Balance;
	for (int i = 0; i < arraySize; i++) {
		if (max < a[i + 1].Balance) {
			max = a[i + 1].Balance;
			result = a[i + 1].Name;
		}


	}
	cout << "The customer with maximum balance is: " << result;
}


void Deposit(string CustName, PERSON *a, float n) {

	float total = 0;

	for (int i = 0; i < 6; i++) {
		if (CustName == a[i].Name)
			total = a[i].Balance + n;
		//a[i].Balance = total;
		
	}

	cout << "Now your new balance is: " << total;
	for (int i = 0; i < 6; i++) {
		if (CustName == a[i].Name)
			a[i].Balance = total;
	}
}


void NewCopy(string filename,PERSON *a, float n) {
	
	ofstream output;
	output.open(filename);
	for (int i = 0; i < n; i++) {

		

		
		output <<a[i].Name <<'\0'<< a[i].Balance <<endl;
		

	}

	output.close();
	

}


int main() {

	ifstream input("data.txt");
	//input.open("data.txt");
	int count = 0;
	const int N = 20;

	string line;
	int temp = 0;


	while (getline(input, line)) {

		istringstream iss(line);
		count++;

	}

	input.close();
	input.open("data.txt");

	PERSON P[N];

	string Cname;
	float deposit = 0;
	float total = 0;

	for (int i = 0; i < N; i++) {

		input.getline(P[i].Name, 100, '\0');

		//input.ignore(256, ' ');
		input >> P[i].Balance;
		input.ignore(1, '\n');


	}

	Display(P, count);
	cout << endl;

	FindRichest(P, count);
	cout << endl;

	cout << "Enter your full name to deposit money: ";
	getline(cin, Cname);
	cout << Cname << ", how much would you like to deposit:";
	cin >> deposit;
	Deposit(Cname, P, deposit);
	cout << endl;
	Display(P, count);
	
	NewCopy("data.txt", P, count);
	input.close();



	system("pause");
	return 0;
}
