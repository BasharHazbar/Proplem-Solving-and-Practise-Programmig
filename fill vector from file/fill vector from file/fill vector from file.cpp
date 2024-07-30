// wrtie data on file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void readFile(string fileName) {

	fstream MyFile;

	MyFile.open(fileName, ios::out | ios::app); // create file mode

	if (MyFile.is_open()) {
		MyFile << "hallo i am 24 years old " << endl;
		MyFile << "hallo i am 24 years old " << endl;
		MyFile << "hallo i am 24 years old " << endl;

		MyFile.close();
	}
}

void printFile(string fileName) {

	fstream myfile;
	myfile.open(fileName, ios::in);

	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			cout << line << endl;
		}
	}

	myfile.close();

}

void fillVectorFromFile(string fileName, vector <string> & data) {
	fstream myfile;
	myfile.open(fileName, ios::in);

	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			data.push_back(line);
		}
	}

	myfile.close();
}

void fillFileFromVecotor(string fileName, vector <string>& data) {
	fstream MyFile;

	MyFile.open(fileName, ios::out ); // create file mode

	if (MyFile.is_open()) {

		for (string& line : data) {
			MyFile << line << endl;
		}

		MyFile.close();
	}
}

int main()
{

	//fstream MyFile;

	//MyFile.open("myfile.txt", ios::out); // create file mode

	//if (MyFile.is_open()) {
	//	MyFile << "hallo i am bashar" << endl;
	//	MyFile << "hallo i am bashar" << endl;
	//	MyFile << "hallo i am bashar" << endl;

	//	MyFile.close();
	//}


	//readFile("myfile2.txt");
	//printFile("myfile2.txt");


	cout << "\n========= file 1 ===========\n" << endl;

	printFile("myfile.txt");

	cout << "\n========= vector ===========\n" << endl;


	vector <string> data;

	fillVectorFromFile("myfile.txt",data);

	for (string& line : data) {
		cout << line << endl;
	}




	cout << "\n========= file 2 ===========\n" << endl;

	fillFileFromVecotor("myfile2.txt", data);

	printFile("myfile2.txt");

}
