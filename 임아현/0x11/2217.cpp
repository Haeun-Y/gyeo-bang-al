#include <bits/stdc++.h>

using namespace std;
int arr[100002];

bool compare(int num1, int num2){
    return num2 < num1;
}


int main()
{
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N, compare);
    
    int MAX = arr[0];
    for(int i = 1; i < N; i++){
        MAX = max(MAX, arr[i] * (i + 1));
    }
    
    cout << MAX;
}