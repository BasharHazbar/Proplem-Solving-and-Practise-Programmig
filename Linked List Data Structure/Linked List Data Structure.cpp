// Linked List Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string"

using namespace std;

class Node {
public:
    int value;
    Node* next;
};


void InsertAtTheBegning(Node*& head, int value) {

    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

void InsertAtTheAfter(Node*& perv_node, int value) {

    if (perv_node == NULL) {
        cout << "\n\nthe perv node can not be null";
        return;
    }
    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = perv_node->next;

    perv_node->next = new_node;

}

void InsertAtTheEnd(Node*& head, int value) {


    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) {
        head == new_node;
        return;
    }

    Node* lastNode = head;

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = new_node;

}

Node* Find(Node* head, int value) {

    while (head != NULL)
    {
        if (head->value == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Node* FindEndNode(Node* head) {

    while (head != NULL)
    {
        if (head->next == NULL) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteNode(Node*& head, int value) {
    Node* Current = head, * Prev = head;

    if (head == NULL) {
        return;
    }

    if (Current->value == value) {
        head = Current->next;
        delete Current;
    }

    while (Current != NULL && Current->value != value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current == NULL) return;

    Prev->next = Current->next;
    delete Current;
}

void deletFirstNode(Node*& head) {
    Node* current = head;

    if (head == NULL) {
        return;
    }

    head = current->next;
    delete current;
}

void deleteLastNode(Node*& head) {

    Node* Current = head, * Prev = head;

    if (head == NULL) {
        return;
    }

    if (Current->next == NULL) {
        head = NULL;
        delete Current;
        return;
    }

    while (Current != NULL && Current->next != NULL)
    {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = NULL;

    delete Current;
}

void printList(Node* head) {

    while (head != NULL)
    {
        cout << head->value << "   ";
        head = head->next;
    }
}

int main()
{

    // defination nodes;
    //Node* node1 = new Node();
    //Node* node2 = new Node();
    //Node* node3 = new Node();
    //Node* node4 = new Node();

    //// set up nodes
    //node1->value = 1;
    //node2->value = 2;
    //node3->value = 3;
    //node4->value = 4;

    //node1->next = node2;
    //node2->next = node3;
    //node3->next = node4;
    //node4->next = NULL;

    // print value by while
    Node* head = NULL;
    InsertAtTheBegning(head, 1);
    InsertAtTheBegning(head, 2);
    InsertAtTheBegning(head, 3);
    InsertAtTheBegning(head, 4);
    InsertAtTheBegning(head, 5);
    InsertAtTheBegning(head, 6);

    printList(head);

    Node* foundValue = Find(head, 3);

    if (foundValue != NULL) {
        cout << "\n\nthe value is found!";
    }
    else {
        cout << "\n\nthe value is not found!";
    }

    Node* addAfterNode = Find(head, 5);

    InsertAtTheAfter(addAfterNode, 20);

    cout << "\n\nadding 20 after ==>  ";

    printList(head);

    InsertAtTheEnd(head, 200);

    cout << "\n\nadding 200 at the end ==> ";

    printList(head);

    cout << "\n\ndelete 20 ==> ";
    deleteNode(head, 20);

    printList(head);

    deletFirstNode(head);

    cout << "\n\nhead value ===============>> " << head->value;

    cout << "\n\nafter delete first node ====> ";

    printList(head);


    deleteLastNode(head);

    cout << "\n\nafter delete last node ====> ";

    printList(head);

    system("pause>0");

}

