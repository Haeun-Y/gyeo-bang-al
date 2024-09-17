//BOJ 15657 N과 M(8)
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> v;
vector<int> seq;
void func1(int cur, int before)
{
    if(cur == m)
    {
        for(int num : seq)
            cout << num << " ";
        cout << "\n";
    }
    else 
    {
        for(int i = before; i<n; i++)
        {
            seq[cur] = v[i];
            func1(cur+1, i);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    seq = vector<int>(m, 0);
    v = vector<int>(n, 0);
    
    for(int i = 0; i<n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    func1(0, 0);
    
    
}
