#include <bits/stdc++.h>

using namespace std;

long long d[92];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    d[1] = 1; 
    d[2] = 1;
    
    for(int i = 3; i <= N; i++){
        d[i] = d[i - 1] + d[i -2];
    }
    cout << d[N];
}