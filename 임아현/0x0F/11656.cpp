#include <bits/stdc++.h>

using namespace std;
string arr[1002];
string str;

int main()
{
    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; i++){
        arr[i] = str.substr(i, len);
    }
    
    sort(arr, arr + len);
    for(int i = 0; i < len; i++){
        cout << arr[i] << '\n';
    }
    
}