// Utility Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "clsUtility.h"
using namespace std;

int main()
{
  

    clsUtility::generateKeys(5, clsUtility::CapitalLatter, 10);

    cout << "\n" <<  clsUtility::generateKey(clsUtility::digitNumber, 10);

    cout << "\n" << clsUtility::getFloor(34.5);


}
