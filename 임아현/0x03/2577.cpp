#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    
    string str = to_string(A * B * C);
    
    int arr [10] = {};
    for(int i =  0; i < str.size(); i++){
        arr[(int)str[i] - 48]++;
    }
    
    for(int i = 0; i < 10; i++){
        cout << arr[i] << '\n';
    }
}