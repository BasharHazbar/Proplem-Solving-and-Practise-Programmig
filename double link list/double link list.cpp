//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value) {


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
}

void insertAfter(Node *& Current, int value) {

    Node* newNode = new Node();

    newNode->value = value;
    newNode->prev = Current;
    newNode->next = Current->next;

    if (Current->next != NULL) {
        Current->next->prev = newNode;
    }

    Current->next = newNode;
}

void insertAtEnd(Node* head, int value) {

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
    }
}

void PrintNodeDetails(Node* head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

Node* find(Node * head,int value) {

    while (head != NULL)
    {
        if (head->value == value) {
            return head;
        }
        head = head->next;
        
    }
    return NULL;
}

void deleteNode(Node *& head, Node*& nodeToDelete) {
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
}

void deleteFirstNode(Node*& head) {
    
    if (head == NULL) {
        return;
    }
    
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteLastNode(Node*& head) {

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

}
// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}


// Print the linked list
void PrintList(Node* head)
{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    Node* N = find(head, 2);

    insertAfter(N, 1000);

    cout << "\n\n";

    PrintList(head);

    insertAtEnd(head,1000);

    cout << "\n\n";
    PrintList(head);


    Node* nodeToDelete = find(head, 1000);
    deleteNode(head,nodeToDelete);

    cout << "\n\n";
    PrintList(head);

    Node* nodeToDelete1 = find(head, 1000);
    deleteNode(head, nodeToDelete1);

    cout << "\n\n";

    PrintList(head);


    deleteFirstNode(head);

    cout << "\n\n";

    PrintList(head);

    deleteLastNode(head);

    cout << "\n\n";

    PrintList(head);

    //cout << "\n\n\n";
    //PrintNodeDetails(head);
    system("pause>0");

}