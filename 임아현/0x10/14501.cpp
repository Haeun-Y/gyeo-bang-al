#include <bits/stdc++.h>

using namespace std;

int N;
int MAX = 0;
int sum[20];
int arr[20][2];

int main()
{
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i = N; i >= 1; i--){
        //퇴사일 넘기지 않는 경우
        if(i + arr[i][0] <= N + 1) sum[i]= max(sum[i + arr[i][0]] + arr[i][1], sum[i + 1]);
        //퇴사일 넘기는 경우 전의 최대값 그대로로
        else sum[i] = sum[i + 1];
    }
    
    for(int i = 1; i <= N + 1; i++){
        MAX = max(MAX, sum[i]);
    }
    
    cout << MAX;
}