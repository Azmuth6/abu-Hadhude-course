#include <iostream>
using namespace std;

class Node 
{
public:

    int Value;
    Node* Next;
    Node* Prev;
};

int main()
{
    Node* head;

    Node* Node1 = NULL;
    Node* Node2 = NULL;
    Node* Node3 = NULL;

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->Value = 1;
    Node2->Value = 2;
    Node3->Value = 3;

    Node1->Next = Node2;
    Node1->Prev = NULL;

    Node2->Next = Node3;
    Node2->Prev = Node1;

    Node3->Next = NULL;
    Node3->Prev = Node2;

    head = Node1;

    while(head != NULL)
    {
        cout << head->Value << " ";
        head = head -> Next;
    }

    return 0;
}