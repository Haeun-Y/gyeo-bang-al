#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[26] = {};
    string name;
    cin >> name;
    int cnt = 0;
    for(char i = 'a'; i <= 'z'; i++){
        for(int j = 0; j < name.size(); j++){
            if(i == name[j])
               arr[cnt]++;
        }
        cout << arr[cnt] << ' ';
        cnt++;
    }
}