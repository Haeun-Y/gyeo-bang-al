//BOJ 3986 좋은 단어 
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int result = 0;
    
    for(int i = 0; i<n; i++)
    {
        string str;
        cin >> str;
        
        stack<char> s;
        
        for(char ch:str)
        {
            if(!s.empty() && s.top() == ch)
                s.pop();
            else s.push(ch);
        }
        
        if(!s.empty()) result++;
    }
    
    cout << result
    
}
