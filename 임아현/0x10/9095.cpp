#include <bits/stdc++.h>

using namespace std;

int d[1000005];
int T, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    //초기값
    d[1] = 1; d[2] = 2; d[3] = 4;
    
    for(int i = 4; i<= 11; i++){
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    
    while(T--){
        int tmp;
        cin >> tmp;
        cout << d[tmp] << '\n';
    }
}