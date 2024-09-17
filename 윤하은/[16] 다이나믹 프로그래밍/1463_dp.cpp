//BOJ 1463 1로 만들기
//dynamic programming
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    vector<int> dp(x+1);

    //초기값 
    dp[1] = 0;
    
    for(int i = 2; i<=x; i++)
    {
        dp[i] = dp[i-1] + 1;

        if(i%3 == 0)
            dp[i] = min(dp[i/3]+1, dp[i]);
        if(i%2 == 0)
            dp[i] = min(dp[i/2]+1, dp[i]);
    }

    cout << dp[x];
}