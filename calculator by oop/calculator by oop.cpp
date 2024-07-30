// calculator by oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class clsCalculator
{

	float resultValue;
	int entireValue;
	string typeOpration;

public:


	void clear() {
		typeOpration = "clear";
		resultValue = 0;
	}

	void add(int number) {
		typeOpration = "add";
		entireValue = number;
		resultValue += number;
	}

	void substract(int number) {
		typeOpration = "substract";
		entireValue = number;
		resultValue -= number;;
	}

	//void substract(int number) {
	//	valueNumner -= number;
	//	typeOpration = "substract";
	//}

	void devide(int number) {
		typeOpration = "devide";
		if (number <= 0) {
			entireValue = 1;
			resultValue /= 1;
		}
		else {
			entireValue = number;
			resultValue /= number;
		}
	}

	void multiple(int number) {
		typeOpration = "multiple";
		entireValue = number;
		resultValue *= number;
	}

	void printResult() {
		cout << "\n\nResult after " << typeOpration << " " << entireValue << " is:- " << resultValue;
	}
};


class clsCalculator2 {
private:
    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation = "Clear";
    float _PreviousResult = 0;

    bool _IsZero(float Number) {
        return (Number == 0);
    }

public:
    void Add(float Number) {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Subtract(float Number) {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Number;
    }

    void Divide(float Number) {
        _LastNumber = Number;
        if (_IsZero(Number)) {
            Number = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }

    void Multiply(float Number) {
        _LastNumber = Number;
        _LastOperation = "Multiplying";
        _PreviousResult = _Result;
        _Result *= Number;
    }

    float GetFinalResults() {
        return _Result;
    }

    void Clear() {
        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }

    void CancelLastOperation() {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }

    void PrintResult() {
        cout << "Result ";
        cout << "After " << _LastOperation << " " << _LastNumber << " is: " << _Result << "\n";
    }
};




int main()
{
	clsCalculator calc;

	calc.clear();
	calc.printResult();

	calc.add(23);
	calc.printResult();

	calc.add(100);
	calc.printResult();

	calc.substract(20);
	calc.printResult();

	calc.devide(2);
	calc.printResult();

	calc.multiple(2);
	calc.printResult();

	calc.devide(0);
	calc.printResult();

	calc.clear();
	calc.printResult();

	calc.add(100);
	calc.printResult();


    clsCalculator2 Calculator1;
    Calculator1.Clear();
    Calculator1.Add(10);
    Calculator1.PrintResult();
    Calculator1.Add(100);
    Calculator1.PrintResult();
    Calculator1.Subtract(20);
    Calculator1.PrintResult();
    Calculator1.Divide(0);
    Calculator1.PrintResult();
    Calculator1.Divide(2);
    Calculator1.PrintResult();
    Calculator1.Multiply(3);
    Calculator1.PrintResult();
    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();
    Calculator1.Clear();
    Calculator1.PrintResult();

	system("pause>0");
	return 0;
}

