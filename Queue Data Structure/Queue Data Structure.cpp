#include <iostream>
#include <queue>


using namespace std;


int main()
{
	queue <int> quNumber;

	quNumber.push(10);
	quNumber.push(11);
	quNumber.push(12);
	quNumber.push(13);
	quNumber.push(14);
	quNumber.push(15);


	while (!quNumber.empty())
	{
		cout << quNumber.front() << "   ";

		quNumber.pop();
	}


	cout << "\n===========================================\n";

	queue <int> myQueue_1;

	myQueue_1.push(10);
	myQueue_1.push(11);
	myQueue_1.push(12);
	myQueue_1.push(13);
	myQueue_1.push(14);
	myQueue_1.push(15);


	queue <int> myQueue_2;

	myQueue_2.push(15);
	myQueue_2.push(14);
	myQueue_2.push(13);
	myQueue_2.push(12);
	myQueue_2.push(11);
	myQueue_2.push(10);

	myQueue_1.swap(myQueue_2);


	while (!myQueue_1.empty())
	{
		cout << myQueue_1.front() << "   ";

		myQueue_1.pop();
	}

	cout << "\n===========================================\n";

	while (!myQueue_2.empty())
	{
		cout << myQueue_2.front() << "   ";

		myQueue_2.pop();
	}

}

