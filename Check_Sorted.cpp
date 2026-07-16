#include <iostream>
using namespace std;
bool CheckSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
int main()
{
    int arr[4] = {2, 4, 3, 2};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    int arr1[4] = {1, 2, 3, 4};
    int size2 = sizeof(arr1) / sizeof(arr1[0]);
    cout << (CheckSorted(arr, size1) ? "True" : "False") << endl;
    cout << (CheckSorted(arr1, size2) ? "True" : "False") << endl;
}