//BOJ 9461 파도반 수열
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> spiral(102, 0);

    spiral[1] = spiral[2] = spiral[3] = 1;
    spiral[4] = spiral[5] = 2;

    for(int i = 6; i<= 100; i++)
        spiral[i] = spiral[i-1] + spiral[i-5];

    
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        cout << spiral[n] << "\n";
    }
}