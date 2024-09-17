//BOJ 1912 연속합
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n);
    vector<int> sum(n);

    for(int i = 0; i<n; i++)
        cin >> seq[i];

    sum[0] = seq[0];

    int result = sum[0];

    for(int i = 1; i<n; i++)
    {
        if(sum[i-1] < 0)
            sum[i] = seq[i];
        else
            sum[i] = sum[i-1] + seq[i];

        if(result < sum[i])
            result = sum[i];
    }

    cout << result;

    


}