#include <bits/stdc++.h>

using namespace std;

int arr[102];
int num[10002];

int main()
{
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    num[0] = 1;
    
    for(int i = 0; i < N; i++){
        for(int j = arr[i]; j <= K; j++){
            num[j] += num[j - arr[i]];
        }
    }
    cout << num[K];
}