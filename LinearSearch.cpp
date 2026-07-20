#include <iostream>
#include <vector>
using namespace std;
class Search
{
public:
    int Linear_Search(vector<int> &arr, int num)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                return i;
            }
        }
        return -1;
    }
};
