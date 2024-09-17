#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;
    cin >> num;
    
    int arr [10] = {};
    
    for(int i =  0; i < num.size(); i++){
        arr[(int)num[i] - 48]++;
    }
    
    if(arr[6] < arr[9]) arr[9] -= (int)((arr[9] - arr[6])/2);
    else if(arr[6] > arr[9]) arr[6] -= (int)((arr[6] - arr[9])/2);
    
    cout << *max_element(begin(arr), end(arr));
}