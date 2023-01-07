//BOJ 3273 두 수의 합
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    
    for(int i = 0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int target;
    cin >> target;

    int result = 0;

    for(int i = 0; i<n-1; i++)
    {
        int searchTarget = target-v[i];
        if(binary_search(v.begin() + i + 1, v.end(), searchTarget))
            result++;
    }

    cout << result;


    
}