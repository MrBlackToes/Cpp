#include <iostream>
using namespace std;
class Stack
{
   public:
   int arr[10];
   int top=-1;
   void push(int n)
   {
    if(top<9)
    {
        top+=1;
        arr[top]=n;
    }
    else
    {
        cout<<"Size exceeded."<<endl;
    }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty."<<endl;
            arr[top]==0;
        }
        else
        {
            top-=1;
        }
    }
    int getsize() const
    {
        return top+1;
    }
    int gettop()
    {
        if(top!=-1)
        {
           return arr[top];         
        }
        else{
        cout<<"Top doesnt exist!"<<endl;
        }
return arr[top];
    }
    bool isempty()
    {
        if(top==-1)
        {
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
        cout<<"Stack isnt empty!"<<endl;
        return -1;
    }
    bool isfull()
    {
        if(top==9)
        {
            cout<<"Stack is Full!"<<endl;
            return 0;
        }
        cout<<"Stack isnt Full!"<<endl;
        return -1;
    }

};
int main()
{
    Stack s1;
    s1.pop();
    cout<<s1.top<<endl;    
    cout<< s1.gettop();
    return 0;
}