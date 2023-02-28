//BOJ 11727 2 x n 타일링2
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> tiling(n+1);
    
    tiling[1] = 1;
    tiling[2] = 3;
    
    for(int i = 3; i<= n; i++)
        tiling[i] = (tiling[i-2] * 2 + tiling[i-1])%10007;
        
    cout << tiling[n];
}
