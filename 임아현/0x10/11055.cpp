#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1002], d[1002];

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        d[i] = arr[i];
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]) d[i] = max(d[i], d[j] + arr[i]);
        }
    }
    
    int MAX = 0;
    for(int i = 0; i < 1002; i++){
        MAX = max(MAX, d[i]);
    }
    
    cout << MAX;
}