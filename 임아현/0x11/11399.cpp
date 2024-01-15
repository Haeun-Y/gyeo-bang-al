#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int arr[1002];
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int sum = 0;
    int min = 0;
    
    for(int i = 0; i < N; i++){
        sum += arr[i];
        min += sum;
    }
    cout << min;
}