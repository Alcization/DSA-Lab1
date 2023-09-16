#include <iostream>
using namespace std;
void printHailstone(int number)
{
    if (number == 1) 
    {
        cout << "1";
        return;
    } else if (number % 2 == 0)
    {
        cout << number << " ";
        printHailstone(number / 2);
    } else
    {
        cout << number << " ";
        printHailstone(number*3 + 1);
    }
}
int main()
{
    printHailstone(5);
}