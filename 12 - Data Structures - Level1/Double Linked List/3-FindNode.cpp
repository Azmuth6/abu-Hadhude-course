#include <iostream>
using namespace std;

class Node 
{
public:

    int Value;
    Node* Next;
    Node* Prev;
};

void AddAtTheBeginning(Node * &head , int Value)
{
    Node *new_Node = new Node();

    new_Node->Value = Value;
    new_Node->Next = head;
   
    new_Node ->Prev = NULL;

    if (head != NULL)
        head ->Prev = new_Node;

    head = new_Node;

}

Node *Find(Node* head , int Value)
{
    while(head !=NULL)
    {
        if (head->Value  == Value)
            return head;
       
        head = head ->Next;
    }
    return NULL;

}

void PrintNodeDetails(Node* head)
{

    if (head->Prev != NULL)
        cout << head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << head->Value << " <--> ";

    if (head->Next != NULL)
        cout << head->Next->Value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->Next;
    }
}


// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->Value << " <--> ";
        head = head->Next;
    }
    cout << "NULL";

}



int main()
{
    Node * head = NULL;

    AddAtTheBeginning(head,1);
    AddAtTheBeginning(head,2);
    AddAtTheBeginning(head,3);
    AddAtTheBeginning(head,4);

    cout << "\nLinked List Content:\n";
    PrintList(head);

    PrintListDetails(head);
    

    cout << "\n\nFinding Node with Value = 3\n";
    Node *Node_Find = Find(head, 3);

    cout << Node_Find->Value << endl;
    cout << "---------------------------------------\n";



    system("pause>0");


}