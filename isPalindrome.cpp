#include <iostream>
#include <string.h>
using namespace std;
string remove_space(string str, int idx = 0) 
{
    if (idx == str.length()) return "";
    if (str[idx] == ' ') return remove_space(str, idx + 1);
    return str[idx] + remove_space(str, idx + 1);
}
bool palindrome(string s)
{   
    if (s.length() <= 1) return true;
    if (s[0] == s[s.length()-1]) return palindrome(s.substr(1, s.length()-2));
    return false;
}
bool isPalindrome(string s)
{
    s = remove_space(s);
    return palindrome(s);
}

int main()
{
    cout << isPalindrome("dad") << endl;
    cout << isPalindrome("do geese see god");
    return 0;
}