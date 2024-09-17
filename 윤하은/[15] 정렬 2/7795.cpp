//BOJ 7795 먹을 것인가 먹힐 것인가
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int tc;
    cin >> tc;

    for(int i =  0; i<tc; i++)
    {
        int n, m;
        cin >> n >> m;

        int result = 0;

        vector<int> a(n);
        vector<int> b(m);

        for(int j = 0; j<n; j++)
            cin >> a[j];
        
        for(int j = 0; j<m; j++)
            cin >> b[j];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int j = 0; j<n; j++)
        {
            for(int k = 0; k<m; k++)
            {
                if(a[j] > b[k])
                    result++;
                else break;
            }
        }
        cout << result << "\n";
    }
}