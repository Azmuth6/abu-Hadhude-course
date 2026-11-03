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
    while(head!=NULL)
    {
        cout << head->value <<endl;
        head = head->next;

    }

    cout << "---------------------------------------\n";
}

Node *Find(Node* head , int Value)
{
    while(head !=NULL)
    {
        if (head->value  == Value)
            return head;
       
        head = head ->next;
    }
    return NULL;

}

int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);

    PrintList(head);

    Node *Node_Find = Find(head, 3);

    cout << Node_Find->value << endl;
    cout << "---------------------------------------\n";

    return 0;


}