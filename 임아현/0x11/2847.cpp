#include <bits/stdc++.h>

using namespace std;

int arr[102];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    int sum = 0;
    
    for(int i = N - 1; i > 0; i--){
        if(arr[i - 1] >= arr[i]){
            sum += arr[i - 1] - (arr[i] - 1);
            arr[i - 1] = arr[i] - 1;
        }
    }
    
    cout << sum;
}