#include <iostream>
using namespace std;

int minBracketInsert(string s, int idx = 0, int count_open_bracket = 0) 
{
    if (idx == s.length()) return count_open_bracket;
    char currentChar = s[idx];
    if (currentChar == '(') return minBracketInsert(s, idx + 1, count_open_bracket + 1);
    else if (currentChar == ')') 
    {
        if (count_open_bracket > 0) return minBracketInsert(s, idx + 1, count_open_bracket - 1);
         else return 1 + minBracketInsert(s, idx + 1, count_open_bracket);
    }
    return minBracketInsert(s, idx + 1, count_open_bracket);
}

int minimumBracketAdd(string s)
{
    return minBracketInsert(s, 0, 0);
}
int main()
{
    cout << minimumBracketAdd("()))((");
    return 0;
}
