#include <bits/stdc++.h>

using namespace std;

long long d[2000];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    //1과 2로 n만들기(단 2가 두 종류임)
    d[1] = 1; 
    d[2] = 3;
    d[3] = 5;
    
    for(int i = 4; i <= N; i++){
        d[i] = (d[i - 1] + d[i - 2] * 2) % 10007;
    }
    
    cout << d[N];
}