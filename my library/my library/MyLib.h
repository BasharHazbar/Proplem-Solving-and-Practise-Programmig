#pragma once

#include <iostream>
using namespace std;

namespace MyLib {

	void test() {
		cout << "Hallo from my library!";
	}

	int sum2Numbers (int num_1, int num_2){
		return num_1 + num_2;
	}

}
