#include <bits/stdc++.h>

using namespace std;

int N;
int MAX = -1001;
int arr[1000002];
int sum[1000002];

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sum[0] = arr[0];
    
    //더하는 게 더 큰지 안 큰지 체크하기
    for(int i = 1; i < N; i++){
        sum[i] = max(sum[i - 1] + arr[i], arr[i]);
    }
    
    //합 중에 가장 작은 값 찾기기
    for(int i = 0; i < N; i++){
        MAX = max(MAX, sum[i]);
    }
    
    cout << MAX;
}