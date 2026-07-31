#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
Node *Reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *last = head->prev;
    Node *temp = head;
    while (temp != nullptr)
    {
        last = temp->prev;
        temp->prev = temp->next;
        temp->next = last;
        temp = temp->prev;
    }
    return last->prev;
}
Node *DoubleListConvert(vector<int> &arr) // Converts vector to Double Linked List
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6}; // Need to use #include<vector> to use
    Node *head = DoubleListConvert(v);
    print(head);
    head = Reverse(head);
    print(head);
}