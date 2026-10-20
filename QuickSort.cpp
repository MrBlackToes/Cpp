#include <iostream>
using namespace std;
int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = Partition(arr, low, high);
        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {4, 6, 2, 5, 7, 9, 1, 3, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}