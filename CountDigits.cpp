#include <iostream>
using namespace std;
int numofdigits(int num)
{
    int count;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}