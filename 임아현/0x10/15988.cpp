#include <bits/stdc++.h>

using namespace std;

int mod = 1000000009;
int num[1000002];

int main()
{
    int N;
    cin >> N;
    num[1] = 1; num[2] = 2; num[3] = 4;
    
    for(int i = 4; i <= 1000000; i++){
        for(int j = 1; j <= 3; j++){
             num[i] = (num[i] + num[i - j]) % mod;   
        }
    }
    
    while(N--){
        int temp;
        cin >> temp;
        cout << num[temp]<<'\n';
    }

}