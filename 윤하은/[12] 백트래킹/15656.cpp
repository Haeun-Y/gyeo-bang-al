//BOJ 15656 N과 M(7)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> seq;
void func1(int cur, int n, int m)
{
    if(cur == m)
    {
        for(int num : seq)
            cout << num << " ";
        cout << "\n";
    }
    else 
    {
        for(int i = 0; i<n; i++)
        {
            seq[cur] = v[i];
            func1(cur+1, n, m);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    seq = vector<int>(m, 0);
    v = vector<int>(n, 0);
    
    for(int i = 0; i<n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    func1(0, n, m);
    
    
}
