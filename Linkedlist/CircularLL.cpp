#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {}
};

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    Node *curr = tail->next; // start from head

    while (curr->data != element)
    {
        curr = curr->next;

        // if full circle completed
        if (curr == tail->next)
        {
            cout << "Element not found\n";
            return;
        }
    }

    Node *newNode = new Node(d);
    newNode->next = curr->next;
    curr->next = newNode;

    if (curr == tail)
        tail = newNode;
}

void print(Node *tail)
{
    if (tail == NULL)
        return;

    Node *temp = tail->next; // head

    while (true)
    {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == tail->next)
            break;
    }
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
        return;

    Node *prev = tail;
    Node *curr = tail->next;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if (curr == tail)
    {
        tail = (curr->next == curr) ? NULL : prev; // single node → tail = NULL
        delete curr;
    }
    else
    {
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);
}
