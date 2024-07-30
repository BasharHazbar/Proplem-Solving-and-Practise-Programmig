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

void fillVectorFromFile(string fileName, vector <string>& fileContent) {
	fstream myfile;
	myfile.open(fileName, ios::in);

	if (myfile.is_open()) {

		string line;

		while (getline(myfile, line)) {
			fileContent.push_back(line);
		}
	}

	myfile.close();
}

void fillFileFromVecotor(string fileName, vector <string>& fileContent) {
	fstream MyFile;

	MyFile.open(fileName, ios::out); // create file mode

	if (MyFile.is_open()) {

		for (string& line : fileContent) {
			if (line != " ") {
				MyFile << line << endl;
			}
		}

		MyFile.close();
	}
}

void UpdateRecordFromFile(string fileName, string record, string upadteRecord) {
	vector <string> fileContent;
	fillVectorFromFile(fileName, fileContent);
	for (string& line : fileContent) {
		if (line == record) {
			line = upadteRecord;
		}
	}
	fillFileFromVecotor(fileName, fileContent);
}

int main()
{
	cout << "\nfile before delete:- \n" << endl;
	printFile("myfile.txt");
	UpdateRecordFromFile("myfile.txt", "saleh","omer");
	cout << "\nfile after delete:- \n" << endl;
	printFile("myfile.txt");

	return 0;
}
