#pragma once
#include <string>
using namespace std;

class clsPerson
{
private:
	string firstName;
	string lastName;
	string email;
	string phone;
public:
	//clsPerson(){

	//}
	clsPerson(string firstName, string lastName, string email,string phone) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->phone = phone;
	}

	string getFisrtName() {
		return firstName;
	}
	void setFisrtName(string firstName) {
		this->firstName = firstName;
	}

	string getlastName() {
		return lastName;
	}
	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	string getEmial() {
		return email;
	}
	void setEmail(string email) {
		this->email = email;
	}
	string getPhone() {
		return phone;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}

};

