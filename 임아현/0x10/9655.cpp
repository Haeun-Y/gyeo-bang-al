#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    //상근이는 홀수 횟수 창영이는 짝수 횟수
    
    if(N % 2 == 0) cout << "CY";
    else cout << "SK";
}