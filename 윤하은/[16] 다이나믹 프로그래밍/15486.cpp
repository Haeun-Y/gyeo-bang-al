//BOJ 15486 퇴사 2
//틀렸습니다.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int, int>> consulting(n+1);
    vector<int> profits(n+2);

    for(int i = 1; i<=n; i++)
    {
        cin >> consulting[i].first;//Ti
        cin >> consulting[i].second;//Pi
    }

    for(int i = n; i>=1; i--)
    {
        if(consulting[i].first + i > n + 1) continue;

        profits[i] = max(profits[i+1], profits[i+consulting[i].first] + consulting[i].second);
    }

    //cout << profits[1];

    int maxProfit = profits[1];

    for(int i = 2; i<= n; i++)
        maxProfit = max(maxProfit, profits[i]);

    cout << maxProfit;
}