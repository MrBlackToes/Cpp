#include <iostream>
using namespace std;
int scndLargest(int arr[], int n)
{
    int largest = arr[0];
    int scndlargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            scndlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > scndlargest)
        {
            scndlargest = arr[i];
        }
    }
    return scndlargest;
}
int main()
{
    int arr[5] = {2, 4, 9, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << scndLargest(arr, size);
    return 0;
}