// wrtie data on file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(string fileName){

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

	printFile("myfile.txt");



   
}
