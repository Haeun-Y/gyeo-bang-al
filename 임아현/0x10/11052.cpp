#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[1002];
    int sum[1002];
    int n;
    cin >> n;
    arr[0] = 0; sum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = arr[i];
    }
    for(int i = 2; i <=n ; i++){
        for(int j = 1; j <= i; j++){
            sum[i] = max(sum[i], sum[i - j] + arr[j]);
        }
    }
    cout << sum[n];
}