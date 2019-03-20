//Geonhyeong Park
//
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
cout << "Enter name: ";
getline(cin, CustName);
cout << CustName << ", how much would you like to deposit:";
cin >> amount;

for (int i = 0; i < arraySize; i++) {
if (CustName == a[i].Name)
	total = a[i].Balance + amount;


}

cout << "Now your new balance is: " << total;
//update deposit amount 
for (int i = 0; i < arraySize; i++) {
	if (CustName == a[i].Name)
		a[i].Balance = total;
}

}

void Display2(PERSON *a,int &arraySize) {
	for (int i = 0; i < arraySize; i ++) {
		cout << a[i].Name << a[i].Balance << endl;
	}
}
void NewCopy(string filename,PERSON *a, float n) {

ofstream output;
output.open(filename);
for (int i = 0; i < n; i++) {




output <<a[i].Name <<" "<< a[i].Balance <<endl;


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

int main() {

ifstream input("data.txt");
input.open("data.txt");
int count = 6;

string Cname;
string line;



while (getline(input, line)) {

istringstream iss(line);
count++;

}


input.close();


float deposit = 0;
float total = 0;



Display(readData(count), count);
cout << endl;

FindRichest(readData(count), count);
cout << endl;

Deposit(readData(count), count, Cname, deposit);
//Display2(readData(count),count);
NewCopy("data.txt", readData(count), count);




system("pause");
return 0;
}
