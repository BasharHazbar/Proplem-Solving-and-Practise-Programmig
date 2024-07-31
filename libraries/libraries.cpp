#include <iostream>
#include "clsLoginScreen.h"

#include "clsCurrency.h"
using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::showLogingScreen()) {
			break;
		}
	}

	//clsCurrency c = clsCurrency::findByCurrencyCode("USD");

	//clsCurrency d = clsCurrency::findByCurrencyName("US Dollar");

	//cout <<  "c.getCurrencyCode() ==> " << c.getCurrencyCode() << endl;

	//cout << "c.getCurrencyName() ==> " << c.getCurrencyName() << endl;

	return 0;
}

