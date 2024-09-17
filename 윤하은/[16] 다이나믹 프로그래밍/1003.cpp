//BOJ 1003 피보나치 함수
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    vector<pair<int, int>> fib(41);
    
    fib[0] = {1, 0};
    fib[1] = {0, 1};

    for(int i = 2; i<=40; i++)
    {
        fib[i].first = fib[i-1].first + fib[i-2].first;
        fib[i].second = fib[i-1].second + fib[i-2].second;
    }

    while(tc--)
    {
        int n;
        cin >> n;
        cout << fib[n].first << " " << fib[n].second << "\n";
    }
}