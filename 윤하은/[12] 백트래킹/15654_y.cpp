#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> seq;
vector<bool> isUsed;
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
            if(isUsed[i]) continue;
            seq[cur] = v[i];
            isUsed[i] = true;
            func1(cur+1, n, m);
            isUsed[i] = false;
        }
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    v = vector<int>(n, 0);
    seq = vector<int>(m, 0);
    isUsed = vector<bool>(n, false);

    for(int i = 0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    func1(0, n, m);
}