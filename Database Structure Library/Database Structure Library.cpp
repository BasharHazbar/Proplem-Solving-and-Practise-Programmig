#include <iostream>
#include "clsDbLinkedList.h"
#include "clsDsQueueu.h"
#include "clsDbStack.h"
#include "clsDsStackArr.h"
#include "clsDsQueueArr.h"
#include "clsDynamicArray.h"
#include "clsMyString.h"

using namespace std;


int main()
{
    //clsDbLinkedList <int> myDbLinkedList;

    //if (myDbLinkedList.isEmpty()) {
    //    cout << "\n\nthe liked list is empty";
    //}
    //else{
    //     cout << "\n\nthe liked list is not empty";
    //}

    //myDbLinkedList.insertAtBeginning(11);
    //myDbLinkedList.insertAtBeginning(20);
    //myDbLinkedList.insertAtBeginning(31);
    //myDbLinkedList.insertAtBeginning(49);
    //myDbLinkedList.insertAtBeginning(52);
    //myDbLinkedList.insertAtBeginning(65);


    //cout << "\n\n";

    //myDbLinkedList.PrintList();

    //clsDbLinkedList <int>::Node* node;

    //node = myDbLinkedList.getNode(3);

    //if (node == NULL) {
    //    cout << "\n\nthe node is empty";
    //}
    //else {
    //    cout << "\n\nthe value of node in index 3 ===>> " << node->value;
    //}

    //cout << "\n\nthe item ==> 'value' on index (2) is ==>> " << myDbLinkedList.getItem(2);


    //cout << "\n\n";
    //myDbLinkedList.updateItem(2,500);

    //myDbLinkedList.PrintList();



    //cout << "\n\n";

    //myDbLinkedList.insertAfter(5,5000);


    //myDbLinkedList.PrintList();

    //cout << "\n\n";

    //clsDbLinkedList <float> myDbLinkedList2;

    //myDbLinkedList2.insertAtBeginning(11.5);
    //myDbLinkedList2.insertAtBeginning(20.34);
    //myDbLinkedList2.insertAtBeginning(31.8);
    //myDbLinkedList2.insertAtBeginning(49.6);
    //myDbLinkedList2.insertAtBeginning(52.5);
    //myDbLinkedList2.insertAtBeginning(65.7);

    //myDbLinkedList2.PrintList();


    cout << "\n==========Queue==================" << endl;

    clsDsQueueu <int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);

    myQueue.print();

    cout << "\n\nthe front value is ==>>> " << myQueue.front();

    cout << "\n\nthe back value is ==>>> " << myQueue.back();

    cout << "\n\nthe size equal ===>> " << myQueue.size();

    cout << "\n\n item(2) == >>> " << myQueue.getItem(2);

    myQueue.updateItem(3, 1000);

    cout << "\n\n\nafter update 1000\n";

    myQueue.print();

    myQueue.insertAfter(3, 2000);

    cout << "\n\n\nafter insertAfter 2000\n";

    myQueue.print();

    myQueue.insertAtBack(100);

    cout << "\n\n\nafter insertAtBack 100\n";

    myQueue.print();

    myQueue.insertAtFront(10000);

    cout << "\n\nafter insertAtFront10000\n";

    myQueue.print();

    cout << "\n\n after pop\n";

    myQueue.pop();

    myQueue.print();

    myQueue.reverse();

    cout << "\n\n\nafter reverse\n";

    myQueue.print();

    cout << "\n\n\nafter clear\n";

    myQueue.clear();

    myQueue.print();


    cout << "\n==========QueueARR==================" << endl;

    clsDsQueueArr <int> myQueueArr;

    myQueueArr.push(1);
    myQueueArr.push(2);
    myQueueArr.push(3);
    myQueueArr.push(4);
    myQueueArr.push(5);
    myQueueArr.push(6);

    myQueueArr.print();

    cout << "\n\nthe front value is ==>>> " << myQueueArr.front();

    cout << "\n\nthe back value is ==>>> " << myQueueArr.back();

    cout << "\n\nthe size equal ===>> " << myQueueArr.size();

    cout << "\n\n item(2) == >>> " << myQueueArr.getItem(2);

    myQueueArr.updateItem(3, 1000);

    cout << "\n\n\nafter update 1000\n";

    myQueueArr.print();

    myQueueArr.insertAfter(3, 2000);

    cout << "\n\n\nafter insertAfter 2000\n";

    myQueueArr.print();

    myQueueArr.insertAtBack(100);

    cout << "\n\n\nafter insertAtBack 100\n";

    myQueueArr.print();

    myQueueArr.insertAtFront(10000);

    cout << "\n\nafter insertAtFront10000\n";

    myQueueArr.print();

    cout << "\n\n after pop\n";

    myQueueArr.pop();

    myQueueArr.print();

    myQueueArr.reverse();

    cout << "\n\n\nafter reverse\n";

    myQueueArr.print();

    cout << "\n\n\nafter clear\n";

    myQueueArr.clear();

    myQueueArr.print();

    cout << "\n==========Stack==================" << endl;


    clsDbStack <int> myStack;


    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);

    myStack.print();

    cout << "\n\nthe top value is ==>>> " << myStack.top();

    cout << "\n\nthe bottom value is ==>>> " << myStack.bottom();

    cout << "\n\nthe size equal ===>> " << myStack.size();

    cout << "\n\n item(2) == >>> " << myStack.getItem(2);

    myStack.updateItem(3, 1000);

    cout << "\n\n\nafter update 1000\n";

    myStack.print();

    myStack.insertAfter(3, 2000);

    cout << "\n\n\nafter insertAfter 2000\n";

    myStack.print();

    myStack.insertAtTop(100);

    cout << "\n\n\nafter insertAtTop 100\n";

    myStack.print();

    myStack.insertAtBottom(10000);

    cout << "\n\nafter insertAtBottom 10000\n";

    myStack.print();


    cout << "\n==========StackArr==================" << endl;


    clsDsStackArr <int> myStackArr;


    myStackArr.push(10);
    myStackArr.push(20);
    myStackArr.push(30);
    myStackArr.push(40);
    myStackArr.push(50);
    myStackArr.push(60);

    myStackArr.print();

    cout << "\n\nthe top value is ==>>> " << myStackArr.top();

    cout << "\n\nthe bottom value is ==>>> " << myStackArr.bottom();

    cout << "\n\nthe size equal ===>> " << myStackArr.size();

    cout << "\n\n item(2) == >>> " << myStackArr.getItem(2);

    myStackArr.updateItem(3, 1000);

    cout << "\n\n\nafter update 1000\n";

    myStackArr.print();

    myStackArr.insertAfter(3, 2000);

    cout << "\n\n\nafter insertAfter 2000\n";

    myStackArr.print();


    myStackArr.clear();

    cout << "\n\n\nafter clear\n";

    myStackArr.print();



 /*   cout << "\n\n after pop\n";
    myStack.pop();

    myStack.print();


    myStack.reverse();

    cout << "\n\n\nafter reverse\n";

    myStack.print();

    myStack.clear();

    cout << "\n\n\nafter clear\n";

    myStack.print();*/

    // for stack
    // req ==> push,size,print,top
    // ,bottom,pop,revrese
    // ,getItem,update,insertAfter,
    // insertAtFront, insertAtBack, clear

    //int* pnx = new int;
    //double* pny = new double;

    //*pnx = 50;

    //*pny = 50.50;


    //cout << *pnx << "        ";


    //cout << *pny << "        ";

    //delete pnx;
    //delete pny;


    ///* if (pnx != nullptr && pny != nullptr) {

    //     cout << *pnx << "        ";

    //     cout << *pny << "        ";
    // }*/

    //int num;
    //cout << "inter number off array ? \n";
    //cin >> num;

    //int* ptr = new int[num];

    //for (int i = 0; i < num; i++) {
    //    cout << "enter student grade ? ";
    //    cin >> *(ptr + i);
    //}

    //for (int i = 0; i < num; i++) {
    //    cout << "the student grade ? ";
    //    cout << *(ptr + i) << endl;

    //}

    //delete[] ptr;

 //   clsDynamicArray <int> myDynamicArray(5);

 //   myDynamicArray.setItem(0, 1);
 //   myDynamicArray.setItem(1, 2);
 //   myDynamicArray.setItem(2, 3);
 //   myDynamicArray.setItem(3, 4);
 //   myDynamicArray.setItem(4, 5);

 //   cout << "the size of array is ? " << myDynamicArray.size();

 //   cout << "\n\n";

 //   cout << "the array is empty ? " << myDynamicArray.isEmpty();

 //   cout << "\n\n";

 //   myDynamicArray.printList();

 //   //myDynamicArray.resize(10);

 //   //cout << "\n\n";

 //   //myDynamicArray.printList();

 ///*   cout << "\n\nitem(2) ===> ";

 //   cout << myDynamicArray.getItem(2);


 //   cout << "\n\nafter reverse \n";

 //   myDynamicArray.reverse();

 //   myDynamicArray.printList();


 //   cout << "\n\nafter delete item at 2 \n";

 //   myDynamicArray.deleteItemAt(2);

 //   myDynamicArray.printList();



 //   cout << "\n\nafter deleteFirstItem \n";

 //   myDynamicArray.deleteFirstItem();

 //   cout << "the size of array is ? " << myDynamicArray.size() << endl;

 //   myDynamicArray.printList();


 //   cout << "\n\nafter deleteLastItem \n";

 //   myDynamicArray.deleteLastItem();

 //   cout << "the size of array is ? " << myDynamicArray.size() << endl;

 //   myDynamicArray.printList();



 //   int index = myDynamicArray.find(4);

 //   if (index == -1) {
 //       cout << "\n\nthe item not found" ;
 //   }
 //   else {
 //       cout << "\n\nthe item found at ==>  " << index;
 //   }

 //   cout << "\n\n";
 //   myDynamicArray.printList();

 //   cout << "\n\nafter deleteItem 4 \n";

 //   myDynamicArray.deleteItem(4);

 //   myDynamicArray.printList();*/



 //   cout << "\n\nafter insertAt 2 \n";

 //   myDynamicArray.insertAt(2,400);


 //   cout << "\n\nthe size of array is ? " << myDynamicArray.size() << endl;

 //   myDynamicArray.printList();

 //   


 //   cout << "\n\n\n\nafter insertAtBegining 2000 \n";

 //   myDynamicArray.insertAtBegining(2000);

 //   myDynamicArray.printList();

 //   cout << "\n\nthe size of array is ? " << myDynamicArray.size() << endl;

 //   


 //   cout << "\n\nafter insertAtEnd 3000 \n";

 //   myDynamicArray.insertAtEnd(3000);

 //   myDynamicArray.printList();

 //   cout << "\n\nthe size of array is ? " << myDynamicArray.size() << endl;




 //   cout << "\n\nafter insertBefor 2 index 5000 \n";

 //   myDynamicArray.insertBefor(2,5000);

 //   myDynamicArray.printList();

 //   cout << "\n\nthe size of array is ? " << myDynamicArray.size() << endl;




 //   cout << "\n\nafter insertAfter 2 index 6000\n";

 //   myDynamicArray.insertAfter(2, 6000);

 //   myDynamicArray.printList();

 //   cout << "\n\nthe size of array is ? " << myDynamicArray.size() << endl;



    //cout << "\n\nafter clear \n";

    //myDynamicArray.clear();

    //myDynamicArray.printList();
 
    clsMyString S1;
    S1.setValue("           ");

    cout << "\nS1 = " << S1.getValue() << endl;

    S1.setValue("Bashar1");

    cout << "\nS1  = " << S1.getValue() << endl;

    S1.setValue("Bashar2");

    cout << "\nS1  = " << S1.getValue() << endl;

    S1.setValue("Bashar4");

    cout << "\nS1  = " << S1.getValue() << endl;

    S1.setValue("Bashar3");

    cout << "\nS1  = " << S1.getValue() << endl;

    cout << "\n\n\t\t\t\tUndo\n";

    S1.Undo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Undo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Undo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Undo();
    cout << "\nS1  = " << S1.getValue() << endl;




    cout << "\n\n\t\t\t\tRndo\n";


    S1.Rndo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Rndo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Rndo();
    cout << "\nS1  = " << S1.getValue() << endl;

    S1.Rndo();
    cout << "\nS1  = " << S1.getValue() << endl;


    system("pause>0");

}

