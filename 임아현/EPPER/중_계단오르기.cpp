#include <bits/stdc++.h>

using namespace std;

int num;
int arr[10002];
int dp[10002][2];

int solution(){
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    
    dp[1][0] = arr[0] + arr[1];
    dp[1][1] = arr[1];
    
    for(int i = 2; i < num; i++){
        dp[i][0] = arr[i] + dp[i - 1][1];
        dp[i][1] = arr[i] + max(dp[i - 2][0], dp[i - 2][1]);
    }
    
    int ans = max(dp[num - 1][0], dp[num - 1][1]);
    return ans;
}

int main()
{
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    cout<< solution();
}