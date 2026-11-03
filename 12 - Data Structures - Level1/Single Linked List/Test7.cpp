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

void insertAtTheEnd(Node * &head , int New_Value)
{
    Node * New_Node = new Node();
   
    New_Node ->value = New_Value;
    New_Node ->next = NULL;

    if (head ==NULL)
    {
        head = New_Node;
        return;
    }

    Node *LastNode = head;
    while (LastNode->next==NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = New_Node;
    return;
}


void DeleteNode(Node * &head , int Value)
{
    Node *Prev = head , *Current = head;

    if(head ==NULL)
        return;

    if (Current ->value == Value)
    {
        head = Current ->next;
        delete Current;
        return;
    }

    while(Current != NULL && Current ->value !=Value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current ==NULL)
        return;
           
    Prev->next = Current->next;

    delete Current;
}

int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);

    PrintList(head);

    DeleteNode(head,2);
    PrintList(head);


    return 0;


}