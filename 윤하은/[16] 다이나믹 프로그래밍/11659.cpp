//BOJ 11659 구간 합 구하기4
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tc;
    cin >> n >> tc;

    vector<int> nums(n+1);
    vector<int> sum(n+1);

    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    sum[0] = 0;
    sum[1] = nums[1];

    for(int i = 2; i <= n; i++)
        sum[i] = sum[i-1] + nums[i];
    
    
    while(tc--)
    {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << "\n";
    }
    
    

}