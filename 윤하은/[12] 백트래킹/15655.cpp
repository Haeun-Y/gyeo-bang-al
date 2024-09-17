//BOJ 15655 N과 M(6)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> seq;
//vector<bool> isUsed;
void func1(int cur, int before, int n, int m)
{
    if(cur == m)
    {
        for(int num : seq)
            cout << num << " ";
        cout << "\n";
        return;
    }
    else
    {
        for(int i = before+1; i<n; i++)
        {
            //if(isUsed[i]) continue;
            seq[cur] = v[i];
            //isUsed[i] = true;
            func1(cur+1, i, n, m);
            //isUsed[i] = false;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        //isUsed.push_back(false);
    }
    for(int i = 0; i<m; i++)
        seq.push_back(0);
    
    sort(v.begin(), v.end());

    func1(0, -1, n, m);

}