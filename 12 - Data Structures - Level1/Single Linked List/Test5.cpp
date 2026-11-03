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

    cout << "---------------------------------------";
}

Node * Find(Node* head , int Value)
{
    while(head !=NULL)
    {
        if (head->value  == Value)
            return head;
       
        head = head ->next;
    }
    return NULL;

}


void insertAfter (Node * Prev_Node , int New_Value)
{
    if (Prev_Node == NULL)
    {
        cout << "The Given Previous Node cannot be Null";
        return;
    }

    Node * New_Node = new Node();
    New_Node ->value = New_Value;
    New_Node ->next = Prev_Node ->next;

    Prev_Node ->next = New_Node;

}


void insertBefore (Node * &head , int New_Value)
{
    Node *Current = head, *Prev = head;
        if (head == NULL)
        {
            cout << "The Given Previous Node cannot be Null";
            return;
        }
    
        if (Current ->value == New_Value)
        {
            AddAtTheBeginning(head,New_Value);
            return;
        }
    
        while (Current->next != NULL&& Current !=NULL)
        {
            Prev = Current;
            Current = Current ->next;
        }
    
        if (Current == NULL)
        {
            cout << "The Given Previous Node cannot be Null";
            return;
        }
    Node * New_Node = new Node();
    New_Node ->value = New_Value;
    New_Node ->next = Current;
    Prev ->next = New_Node;

}


int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);

    PrintList(head);

    Node * Node_Find =Find(head,6);

    if (Node_Find != NULL )
    {
        cout << "Number Found :-) ";
    }
    else 
    {
        cout << "Number Not Found :-( ";
    }


    return 0;


}