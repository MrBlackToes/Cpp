#include <iostream>
#include <vector>
using namespace std;
void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *Left = new int[n1];
    int *Right = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        Left[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        Right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
    delete[] Left;
    delete[] Right;
}
void sort(int arr[], int left, int right)
{

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[] = {60, 80, 30, 10, 100, 50, 90, 70, 40, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, 0, size - 1);
    cout << "After Sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}