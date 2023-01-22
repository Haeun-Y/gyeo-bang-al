//BOJ 1874 스택 수열
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i =0; i<n; i++)
        cin >> v[i];

    stack<int> s;
    string result = "";
    //vector<bool> isUsed(n+1, false);
    int maxNum = 0;

    for(int i = 0; i<n; i++)
    {
        if(!s.empty() && s.top() == v[i])
        {
            result += "-";
            s.pop();
        }
        else if(s.empty() || (!s.empty() && s.top() < v[i]))
        {
            for(int j = maxNum+1; j<= v[i]; j++)
            {
                result += "+";
                s.push(j);
                maxNum = j;
            }
            result += "-";
            s.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    
    for(char ch:result)
        cout << ch << "\n";
}