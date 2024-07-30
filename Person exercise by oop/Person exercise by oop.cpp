// static value in class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class clsPerson {
	long id;
	string firstName;
	string lastName;
	string email;
	string phone;
public:
	clsPerson(long id,string firstName, string lastName, string email, string phone) {
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->phone = phone;
	}

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return id;
	}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}
	string getFirstName() {
		return firstName;
	}

	//void setFirstName(string firstName) {
	//	this->firstName = firstName;
	//}
	//string getFirstName() {
	//	return firstName;
	//}
	void setLastName(string lastName) {
		this->lastName = lastName;
	}
	string getLastName() {
		return lastName;
	}
	void setEmail(string email) {
		this->email = email;
	}
	string getEmail() {
		return email;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	string getPhone() {
		return phone;
	}
	void print() {
		cout << "info\n";
		cout << "---------------------------------\n";
		cout << "ID          : " << id << endl;
		cout << "First Name  : " << firstName << endl;
		cout << "Last Name   : " << lastName << endl;
		cout << "email		 : " << email << endl;
		cout << "phone		 : " << phone << endl;
		cout << "---------------------------------\n";
	}
	void sendEmail(string subject, string body) {
		cout << "the following message sent successfly to email: " << email << endl;
		cout << "subject : " << subject << endl;
		cout << "body  : " << body << endl;
	}
	void sendPhone(string message) {
		cout << "the following message sent successfly to phone: " << phone << endl;
		cout << message << endl;
		
	}
};

class clsEmployee : public  clsPerson{
private:
	string title;
	string department;
	string salary;
public:
	clsEmployee(long id, string firstName, string lastName, string email, string phone, string title, string department, string salary)
		: clsPerson(id, firstName, lastName, email, phone)
	{
		this->title = title;
		this->department = department;
		this->salary = salary;

	}
	void setTilte(string title) {
		this->title = title;
	}
	string getTitle() {
		return title;
	}

	void setDepartment(string department) {
		this->department = department;
	}
	string getDepartment() {
		return department;
	}
	void setSalary(string salary) {
		this->salary = salary;
	}
	string getSalary() {
		return salary;
	}


	void print() {
		cout << "info\n";
		cout << "---------------------------------\n";
		cout << "ID          : " << getId() << endl;
		cout << "First Name  : " << getFirstName() << endl;
		cout << "Last Name   : " << getLastName() << endl;
		cout << "email		 : " << getEmail() << endl;
		cout << "phone		 : " << getPhone() << endl;
		cout << "title		 : " << title << endl;
		cout << "department	 : " << department << endl;
		cout << "salary		 : " << salary << endl;
		cout << "---------------------------------\n";
	}

	//void sendEmail(string subject, string body) {
	//	clsPerson::sendEmail(subject, body);
	//}

	//void sendPhone(string message) {
	//	clsPerson::sendPhone(message);
	//}

};

class clsProgrammer : public clsEmployee
{
private:
	string  mainProgrammingLanguage;

public:
	clsProgrammer(long id, string firstName, string lastName, string email, string phone, string title, string department, string salary,string mainProgrammingLanguage)
	: clsEmployee(id,firstName,lastName,email,phone,title,department,salary)
	{
		this->mainProgrammingLanguage = mainProgrammingLanguage;
	}
	void setMainProgrammingLanguage(string mainProgrammingLanguage) {
		this->mainProgrammingLanguage = mainProgrammingLanguage;
	}
	string getMainProgrammingLanguage() {
		return mainProgrammingLanguage;
	}
	void print() {
		cout << "---------------------------------\n";
		cout << "ID          : " << getId() << endl;
		cout << "First Name  : " << getFirstName() << endl;
		cout << "Last Name   : " << getLastName() << endl;
		cout << "email		 : " << getEmail() << endl;
		cout << "phone		 : " << getPhone() << endl;
		cout << "title		 : " << getTitle() << endl;
		cout << "department	 : " << getDepartment() << endl;
		cout << "salary		 : " << getSalary() << endl;
		cout << "Programming Language		 : " << getMainProgrammingLanguage() << endl;
		cout << "---------------------------------\n";
	}
};
// 090099
class clsPerson1
{

private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson1(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Read Only Property
    int ID()
    {
        return _ID;
    }

    //Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string FirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string LastName()
    {
        return _LastName;
    }

    //Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string Email()
    {
        return _Email;
    }

    //Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string Phone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID       : " << _ID;
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }

    void SendEmail(string Subject, string Body)
    {

        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;

    }

    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }


};

class clsEmployee1 : public clsPerson1
{

private:
    string _Title;
    string _Department;
    float _Salary;

public:

    clsEmployee1(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
        : clsPerson1(ID, FirstName, LastName, Email, Phone)

    {

        _Title = Title;
        _Department = Department;
        _Salary = Salary;

    }

    //Property Set
    void setTitle(string Title)
    {
        _Title = Title;
    }

    //Property Get
    string Title()
    {
        return _Title;
    }

    //Property Set
    void setDepartment(string Department)
    {
        _Department = Department;
    }

    //Property Get
    string Department()
    {
        return _Department;
    }

    //Property Set
    void setSalary(float Salary)
    {
        _Salary = Salary;
    }

    //Property Get
    float Salary()
    {
        return _Salary;
    }

    void Print()
    {

        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << ID();
        cout << "\nFirstName : " << FirstName();
        cout << "\nLastName  : " << LastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << Email();
        cout << "\nPhone     : " << Phone();

        cout << "\nTitle     : " << _Title;
        cout << "\nDepartment: " << _Department;
        cout << "\nSalary    : " << _Salary;

        cout << "\n___________________\n";

    }

};

class clsDeveloper1 : public clsEmployee1

{

private:
    string _MainProgrammingLanguage;

public:

    clsDeveloper1(int ID, string FirstName, string LastName, string Email, string Phone, string Title,
        string Department, float Salary, string MainProgrammingLanguage)
        : clsEmployee1(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)

    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    //Property Set
    void setMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    //Property Get
    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    void Print()
    {

        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << ID();
        cout << "\nFirstName : " << FirstName();
        cout << "\nLastName  : " << LastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << Email();
        cout << "\nPhone     : " << Phone();

        cout << "\nTitle     : " << Title();
        cout << "\nDepartment: " << Department();
        cout << "\nSalary    : " << Salary();
        cout << "\nPLanguage : " << MainProgrammingLanguage();
        cout << "\n___________________\n";

    }

};

int main()
{
	//clsPerson person(20, "Bashar", "Abdulwahab", "hbashar99@gmail.com", "856481767676767");
	//person.print();
	//person.sendEmail("Hi","how are you");
	//person.sendPhone("how are you ");

	clsEmployee employee(223, "Basr", "Abdulwb", "@gmail.com", "856481767676767"," "," "," ");
	employee.print();
	employee.sendEmail("Hi", "how are you");
	employee.sendPhone("how are you ");




	clsProgrammer programmer(22234, "BasrWERWE", "Abdulwb", "@gmail234.com", "856481234324767676767", "234 ", " 234", "234 ","234");
	programmer.print();
	programmer.getMainProgrammingLanguage();
   
    programmer.sendPhone("hallo");


    clsDeveloper1 developer1(2342, "BasrWERWE", "Abdulwb", "@gmail234.com", "856481234324767676767", "234 ", " 234",345.345, "234");
    developer1.SendEmail("hi", "asndfjhashgdf");

	system("pause>0");

	return 0;
}


