#pragma once

#include <iostream>
#include <string>
#include "clsDsStackArr.h"

using namespace std;

class clsMyString
{
private:
	string value;
	clsDsStackArr <string> myStackUndo;
	clsDsStackArr <string> myStackRedo;

public:
	void setValue(string value) {
		myStackUndo.push(value);
		this->value = value;
	}

	string getValue() {
		return this->value;
	}

	void Undo() {
		if (!myStackUndo.isEmpty()) {

			myStackRedo.push(getValue());

			setValue(myStackUndo.top());

			myStackUndo.pop();
	
		}
	}

	void Rndo() {
		if (!myStackRedo.isEmpty()) {

			myStackUndo.push(getValue());

			setValue(myStackRedo.top());

			myStackRedo.pop();

		}
	}
};

