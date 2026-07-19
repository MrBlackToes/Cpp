#include<iostream>
using namespace std;
int rotatearrayby1(int arr[],int s)
{
    int temp=arr[0];
    for(int i=0;i<s;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[s-1]=temp;
    return arr;
}
