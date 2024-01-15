#include <bits/stdc++.h>

using namespace std;

int N;
int d[100005];

int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(int i = 1; i <= N; i++){
        d[i] = i; //최대 i개
        for(int j = 1; j * j < i + 1; j++){
            d[i] = min(d[i], d[i - j * j] + 1); //제곱수로 만들 수 있는 것 update
        }
        
    }

    cout << d[N];                                                                                         
}