#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

void AddAtTheBeginning(Node*& head, int Value)
{
    Node* new_Node = new Node();
    new_Node->value = Value;
    new_Node->next = head;
    head = new_Node;
}

void PrintList(Node* head)
{
    while (head != NULL)
    {
        cout << head->value << endl;
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

void insertAfter(Node* Prev_Node, int New_Value)
{
    if (Prev_Node == NULL)
    {
        cout << "The Given Previous Node cannot be Null\n";
        return;
    }

    Node* New_Node = new Node();
    New_Node->value = New_Value;
    New_Node->next = Prev_Node->next;
    Prev_Node->next = New_Node;
}

void insertAtTheEnd(Node*& head, int New_Value)
{
    Node* New_Node = new Node();
    New_Node->value = New_Value;
    New_Node->next = NULL;

    if (head == NULL)
    {
        head = New_Node;
        return;
    }

    Node* LastNode = head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = New_Node;
}

// ✅ نسخة صحيحة من insertBefore
void insertBefore(Node*& head, Node* NodeAfter, int New_Value)
{
    if (head == NULL || NodeAfter == NULL)
    {
        cout << "Invalid input.\n";
        return;
    }

    // لو العنصر اللي بعده هو الرأس نفسه
    if (head == NodeAfter)
    {
        AddAtTheBeginning(head, New_Value);
        return;
    }

    Node* Current = head;
    while (Current->next != NULL && Current->next != NodeAfter)
    {
        Current = Current->next;
    }

    if (Current->next == NULL)
    {
        cout << "NodeAfter not found in list.\n";
        return;
    }

    Node* New_Node = new Node();
    New_Node->value = New_Value;
    New_Node->next = NodeAfter;
    Current->next = New_Node;
}

void DeleteNode(Node* &head, int Value)
{
    if (head == NULL)
        return;

    Node* Prev = NULL;
    Node* Current = head;

    if (head->value == Value)
    {
        head = head->next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->value != Value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current == NULL)
        return;

    Prev->next = Current->next;
    delete Current;
}

void DeleteFirstNode(Node* &head)
{
    if (head == NULL)
        return;

    Node* Current = head;
    head = Current->next;
    delete Current;
}

void DeleteLastNode(Node* &head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* Current = head;
    Node* Prev = NULL;

    while (Current->next != NULL)
    {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = NULL;
    delete Current;
}

int main()
{
    Node* head = NULL;

    AddAtTheBeginning(head, 1);
    AddAtTheBeginning(head, 2);
    AddAtTheBeginning(head, 3);
    AddAtTheBeginning(head, 4);

    PrintList(head);

    DeleteNode(head, 2);
    PrintList(head);

    // تجربة insertBefore:
    Node* node1 = Find(head, 1);
    insertBefore(head, node1, 99);
    PrintList(head);

    return 0;
}
