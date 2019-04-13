//Geonhyeong Park
//CPSC-301-03
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


void Deposit(PERSON *a, int &arraySize, string CustName, float amount) {

	float total = 0;
	string firstname, lastname;
	cout << "Enter name: ";

	cin >> firstname >> lastname;
	cin.ignore();
	CustName = firstname + " " + lastname;

	//getline(cin, CustName);
	cout << CustName << ", how much would you like to deposit:";
	cin >> amount;

	for (int i = 0; i < arraySize; i++) {
		if (CustName == a[i].Name) {
			total = a[i].Balance + amount;
			a[i].Balance = total;
		}
	}

	cout << "Now your new balance is: " << total << endl;
	

}


void NewCopy(string filename, PERSON *a, float n) {

	ofstream output;
	output.open(filename);
	for (int i = 0; i < n; i++) {




		output << a[i].Name << " " << a[i].Balance << endl;


	}

	output.close();

	cout << "File Updated..." << endl;

}

PERSON *readData(int &N) {
	PERSON *P;
	P = new PERSON[N];
	ifstream input("data.txt");




	string firstN;
	string lastN;
	string fullN;
	float deposit = 0;
	float total = 0;

	for (int i = 0; i < N; i++) {

		input >> firstN >> lastN >> P[i].Balance;

		fullN = firstN + " " + lastN;
		strcpy_s(P[i].Name, fullN.c_str());

	}


	input.close();
	return P;
}

void printmenu() {
	cout << "Please enter a choice:" << endl;
	cout << "1. Display records" << endl;
	cout << "2. Deposit funds" << endl;
	cout << "3. Find Highest Balance" << endl;
	cout << "4. Update records" << endl;
	cout << "5. Exit the program" << endl;
}

int main() {

	ifstream input("data.txt");

	
	int count = 0;
	string Cname;
	string line;
	PERSON p;


	while (getline(input, line)) {


		count++;

	}
	

	input.close();

	PERSON *p1 = readData(count);
	float deposit = 0;
	int choice;
	do
	{
		printmenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			// Act on display
			Display(p1, count);
			break;

		case 2:
			// Act on deposit
			Deposit(p1, count, Cname, deposit);
			break;

		case 3:
			// Act highest balance
			FindRichest(p1, count);
			break;

		case 4:
			// Act on update records
			NewCopy("data.txt", p1, count);
			break;

		case 5:
			// Must call update records here before exiting the program
			Display(p1, count);
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 5);





	system("pause");
	return 0;
}
