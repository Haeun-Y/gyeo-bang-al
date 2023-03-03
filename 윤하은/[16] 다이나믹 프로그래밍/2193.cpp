//BOJ 2193 이친수
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> pinary(n+1);
    
    pinary[1] = pinary[2] = 1;
    
    for(int i = 3; i<=n; i++)
        pinary[i] = pinary[i-2] + pinary[i-1];
    
    cout << pinary[n];
}