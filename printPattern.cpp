#include <iostream>
using namespace std;

int travel(int n, int m, bool flag)
{
    if (flag){
        n=n-5;
        cout << n << " ";
        if (n <= 0) flag = 0;
        travel(n, m, flag);
    }
    else 
    {
        n = n + 5;
        if (n < m){
            cout << n << " ";
            travel(n, m, flag);
        }
        else cout << n;
    }
    return n;
}
void printPattern(int n)
{
    int m=n;
    bool flag=1;
    cout<<n<<' ';
    travel(n, m, flag);

}

int main()
{
    printPattern(16);
    return 0;
}