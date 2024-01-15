#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int arr[n] = {};
    int freq[2000001] = {};
    
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    int x;
    cin >> x;
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(x - arr[i] > 0 && freq[x-arr[i]] == 1) cnt++;
    }
    if(n == 1) cout << 0;
    else cout << cnt / 2;
}