#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector <string> vString, string delim) {
	string text;
	for (string& word : vString) {
		text += word + delim;
	}
	return text.substr(0,text.length() - delim.length());
}

int main()
{
	vector <string> vString = {"bashar","ali","saleh","farhaan"};

	cout << "join string on vector are:- " << joinString(vString, "======");
   
}
