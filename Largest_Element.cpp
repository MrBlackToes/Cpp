#include <iostream>
using namespace std;
int LargestElement(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest Element in the array is:" << largest << endl;
    return largest;
}
int main()
{
    int arr[5] = {5, 9, 4, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    LargestElement(arr, size);
}