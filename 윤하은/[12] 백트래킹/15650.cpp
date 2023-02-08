//BOJ N과 M(2)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void func(int n, int m, int cur)
{
    if(cur == m)
    {
        for(int i =0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        int start = (cur > 0) ? cur -1 : cur;
        
        for(int i = v[start]+1; i<=n; i++)
        {
            v[cur] = i;
            func(n, m, cur+1);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i<=n; i++)
        v.push_back(0);
    
    func(n, m, 0);
}
