#include <iostream>
using namespace std;
int findLCM(int a, int b)
{
    static int count = 1;    
    if((a * count) % b == 0)
    {
        return count;
    }
    else
    {
        count++;
        findLCM(a, b);
        return a * count;
    }
}

int main()
{
    cout << findLCM(10, 102);
}