//BOJ 14501 퇴사
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> consulting(n+1);

    int result = 0;

    for(int i = 1; i<=n; i++)
    {
        cin >> consulting[i].first >> consulting[i].second;
        int maxProfit = 0;

        if(consulting[i].first + i > n+1) continue;

        for(int j = 1; j<i; j++)
        {
            if(consulting[j].first + j > i) continue;
            if(consulting[j].second > maxProfit)
                maxProfit = consulting[j].second;
        }
        consulting[i].second += maxProfit;
        
        if(result < consulting[i].second)
            result = consulting[i].second;
    }

    cout << result;


}