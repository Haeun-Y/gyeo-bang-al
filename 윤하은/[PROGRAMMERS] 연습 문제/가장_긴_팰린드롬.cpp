#include <bits/stdc++.h>
using namespace std;
int maxPalindrome(string s, int start)
{
    int result = 1;
    int length = s.length();
    
    for(int i = start+1; i<length; i++)
    {
        string cur = s.substr(start, i-start+1);
        //cout << "start with " << start << " : " << cur << "\n";
        string curR = "";
        for(int i = cur.length()-1; i>= 0; i--)
            curR += cur[i];
        if(cur == curR)
            result = cur.length();
    }
    return result;
    
}
int solution(string s)
{
    int answer=0;
    
    int length = s.length();
    
    for(int i = 0; i<length; i++)
        answer = max(answer, maxPalindrome(s, i));

    return answer;
}