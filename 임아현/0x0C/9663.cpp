#include <bits/stdc++.h>

using namespace std;

int N;
int cnt = 0;
int arr[10]; //수열 담음
bool isused1[20]; //y열 점유 상태
bool isused2[40]; //대각선 점유 상태
bool isused3[40]; //대각선 점유 상태

void func(int cur){
    if(cur == N){
        cnt++;
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1])
           continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + N - 1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + N - 1] = 0;
        
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    func(0);
    cout << cnt;
    
}