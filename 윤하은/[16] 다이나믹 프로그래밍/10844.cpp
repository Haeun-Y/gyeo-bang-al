//BOJ 10844 쉬운 계단수
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> stair(n+1, vector<int>(10));

    for(int i = 1; i<10; i++)
        stair[1][i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(j == 0)
                stair[i][j] = stair[i-1][j+1] % 1000000000;
            else if(j == 9)
                stair[i][j] = stair[i-1][j-1] % 1000000000;
            
            else
                stair[i][j] = ((long long)stair[i-1][j-1] + stair[i-1][j+1]) % 1000000000;
        }

    }

    long long result = 0;
    for(int i = 0; i<10; i++)
        result = (result + stair[n][i]) % 1000000000;

    cout << result;
    
}