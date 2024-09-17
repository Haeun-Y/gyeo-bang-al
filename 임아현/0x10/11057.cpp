#include <bits/stdc++.h>

using namespace std;

int arr[10002][12]; 
int mod = 10007;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < 10; i++){
        arr[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            int sum = 0;
            for(int k = j; k < 10; k++){
                sum = (sum + arr[i - 1][k]) % mod;
            }
            arr[i][j] = sum;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 10; i++){
        ans = (ans + arr[N][i]) % mod;
    }
    cout << ans;
}