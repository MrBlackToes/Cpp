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
        next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
void Traverse(Node *tail)
{
    if (tail == nullptr)
        return;
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
Node *insertatstart(int value, Node *&tail)
{
    if (tail == nullptr)
    {
        tail = new Node(value);
        tail->next = tail;
        return tail;
    }
    Node *node = new Node(value);
    node->next = tail->next;
    tail->next = node;
    return tail;
}
Node *insertatend(int value, Node *&tail)
{
    if (tail == nullptr)
    {
        tail = new Node(value);
        tail->next = tail;
        return tail;
    }
    Node *temp = new Node(value);
    temp->next = nullptr;
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}
Node *insertatindex(int pos, int value, Node *&tail)
{
    if (tail == nullptr)
    {
        return new Node(value, tail);
    }
    if (pos < 0)
    {
        return tail;
    }
    if (pos == 1)
    {
        insertatstart(value, tail);
        return tail;
    }
    Node *temp = tail->next;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == tail->next)
    {
        return tail;
    }
    if (temp == tail)
    {
        insertatend(value, tail);
    }
    else
    {
        Node *ptr = new Node(value);
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return tail;
}
Node *deletestart(Node *tail)
{
    if (tail == nullptr)
    {
        return nullptr;
    }
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return tail;
    }
    Node *ptr = tail->next;
    tail->next = ptr->next;
    delete ptr;
    return tail;
}
Node *deleteend(Node *tail)
{
    Node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    delete tail;
    tail = temp;
    return tail;
}
Node *deleteatindex(Node *tail)
{
    if (tail == nullptr)
    {
        return nullptr;
    }
    if (tail->next == tail)
    {
        delete tail;
        return nullptr;
    }
    int pos;
    cout << "Enter the position to delete:";
    cin >> pos;
    if (pos < 1)
    {
        cout << "Invalid Index." << endl;
        return tail;
    }

    if (pos == 1)
    {
        return deletestart(tail);
    }
    Node *temp = tail->next;
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == temp)
    {
        cout << "Out of Bounds." << endl;
        return tail;
    }
    Node *temp2 = temp->next;
    if (temp2 == tail)
    {
        return deleteend(tail);
    }
    temp->next = temp2->next;
    delete temp2;
    return tail;
}
int main()
{
    Node *tail = new Node(5);
    tail->next = tail;
    insertatstart(10, tail);
    insertatend(20, tail);
    insertatindex(3, 25, tail);
    Traverse(tail);
    // tail = deletestart(tail);
    // tail = deleteend(tail);
    tail = deleteatindex(tail);
    Traverse(tail);
    return 0;
}