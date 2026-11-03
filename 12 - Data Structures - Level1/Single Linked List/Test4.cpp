#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
    
};


void AddAtTheBeginning(Node* &head,int Value)
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

Node* Find(Node* head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
            return head;

        head = head->next;
    }
    return NULL;

}


void insertAfter (Node* Prev_Node , int New_Value)
{
    if (Prev_Node == NULL)
    {
        cout << "The Given Previous Node cannot be Null";
        return;
    }


    Node* New_Node = new Node();

    New_Node->value = New_Value;
    New_Node->next = Prev_Node->next;

    Prev_Node->next = New_Node;

}


int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);
    AddAtTheBeginning(head,8);

    PrintList(head);

    Node * Node_Find =Find(head,3);

    insertAfter(Node_Find,100);

    PrintList(head);

    


    return 0;


}