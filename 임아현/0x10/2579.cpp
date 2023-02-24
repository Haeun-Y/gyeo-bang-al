#include <bits/stdc++.h>

using namespace std;

int arr[302] = {0};
int sum[302];
int N;

int stair(int N){
    if(sum[N] == -1){
        return sum[N] = max(stair(N -2), stair(N - 3) + arr[N - 1]) + arr[N];
    }
    return sum[N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    fill_n(sum, 302, -1);
    
    sum[1] = arr[1];
    
    if(N >= 2){
        sum[2] = arr[1] + arr[2];
    }
    
    cout << stair(N);
    
}