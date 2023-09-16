#include <iostream>
using namespace std;
int myArrayToInt(char *str, int n) {
    if (n == 0) {
        return 0;
    }
    int lastDigit = str[n - 1] - '0';
    int result = myArrayToInt(str, n - 1) * 10 + lastDigit;
    return result;
}
int main()
{
    char str[] = "2022223";
    cout << myArrayToInt(str, 7);
    return 0;
}