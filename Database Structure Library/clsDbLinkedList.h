#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDbLinkedList
{
protected:
    int _Size = 0;

public:
    class Node
    {
        public:
            T value;
            Node* next;
            Node* prev;
    };

    Node* head = NULL;

    void insertAtBeginning(T value) {


        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;
    }

    void insertAfter(Node* Current,T value) {

        Node* newNode = new Node();

        newNode->value = value;
        newNode->prev = Current;
        newNode->next = Current->next;

        if (Current->next != NULL) {
            Current->next->prev = newNode;
        }

        Current->next = newNode;
        _Size++;
    }

    bool insertAfter(int index, T newValue) {

        Node* itemNode = getNode(index);

        if (itemNode != nullptr) {
            insertAfter(itemNode, newValue);
            return true;
        }

        return false;
    }

    void insertAtEnd(T value) {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            newNode->prev = current;
            current->next = newNode;
        }
        _Size++;
    }

    Node* find(T value) {

        Node* Current = head;
        while (Current != NULL)
        {
            if (Current->value == value) {
                return Current;
            }
            Current = Current->next;

        }
        return NULL;
    }

    void deleteNode(Node *& nodeToDelete) {
        if (head == NULL || nodeToDelete == NULL) {
            return;
        }

        if (head == nodeToDelete) {
            head = nodeToDelete->next;
        }

        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        if (nodeToDelete->prev != NULL) {
            nodeToDelete->prev->next = nodeToDelete->next;
        }

        delete nodeToDelete;
        _Size--;
    }

    void deleteFirstNode() {

        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void deleteLastNode() {

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            head = NULL;
            delete head;
            return;
        }

        Node* current = head;

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;

        current->next = NULL;

        delete temp;
        _Size--;

    }

    void PrintListDetails()

    {
        cout << "\n\n";
        Node* Current = head;
        while (Current != NULL) {
            PrintNodeDetails(Current);
            Current = Current->next;
        }
    }

    void PrintNodeDetails()
    {
        Node* Current = head;
        if (Current->prev != NULL)
            cout << Current->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << Current->value << " <--> ";

        if (Current->next != NULL)
            cout << Current->next->value << "\n";
        else
            cout << "NULL";

    }

    void PrintList()
    {

        Node* Current = head;
        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }

    }

    int size() {
        return _Size;
    }

    bool isEmpty() {
        return _Size == 0;
    }

    void clear() {
        while (!isEmpty())
        {
            deleteFirstNode();
        }
    }

    //void clear() {
    //    while (_Size > 0)
    //    {
    //        deleteFirstNode(); ///
    //    }
    //} // curent ==> perv


    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* getNode(int index) {
        short counter = 0;
        Node* Current = head;
        if (index > _Size - 1 || index < 0) {
            return NULL;
        }
        while (Current != NULL && Current->next != NULL)
        {
            if (counter == index) {
                break;
            }
            counter++;
            Current = Current->next;

        }
        return Current;
    }

    T getItem(int index) {

        Node* nodeItem = getNode(index);

        if (nodeItem == NULL) {
            return NULL;
        }
        return nodeItem->value;
    }

    bool updateItem(int index, T newValue) {
        Node* itemNode = getNode(index);

        if (itemNode != nullptr) {
            itemNode->value = newValue;
            return true;
        }

        return false;
    }
};

