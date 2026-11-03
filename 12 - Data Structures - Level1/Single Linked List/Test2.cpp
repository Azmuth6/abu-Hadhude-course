#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
    
};


void AddAtTheBeginning(Node * &head,int Value)
{
    Node *new_Node = new Node();

    new_Node->value = Value;
    new_Node->next = head;

    head = new_Node;

}

void PrintList(Node* head)
{
    cout << "---------------------------------------\n";
    while(head!=NULL)
    {
        cout << head->value <<endl;
        head = head->next;

    }

    cout << "---------------------------------------";
}



int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);

    PrintList(head);

    return 0;


}