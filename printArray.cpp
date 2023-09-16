#include <iostream>
using namespace std;
void printArray(int n)
{   if (n == 0) {
        cout << n;
        return;
    }
    printArray(n-1);
    cout << ", ";
    cout << n;
    return;
}
int main() 
{   printArray(10);
    return 0;
}