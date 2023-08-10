#include <bits/stdc++.h>

using namespace std;

string arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        arr[i] = str.substr(i);
    }
    
    sort(arr, arr + str.length());
    
    for(int i = 0; i < str.length(); i++){
        cout << arr[i] << '\n';
    }
}