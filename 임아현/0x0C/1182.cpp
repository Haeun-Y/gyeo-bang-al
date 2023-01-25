#include <bits/stdc++.h>

using namespace std;

int N, S;
int cnt = 0;
int arr[22]; //수열 담음


void func(int cur, int sum){
    if(cur == N){
        if(sum == S) cnt++;
        return;
    }
    func(cur + 1, sum); //더하는 경우
    func(cur + 1, sum + arr[cur]); //안 더하는 경우
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    func(0, 0);
    if(S == 0) cnt--; //공집합인 경우 (다 안 골라서 0) 제외
    cout << cnt;
    
}