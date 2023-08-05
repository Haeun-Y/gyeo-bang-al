//BOJ 15651 N과 M(3)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void findSeq(int n, int m, int cur)
{
  if(cur == m)
  {
    for(int num : v)
      cout << num << " ";
    cout << "\n";
    return;
  }
  else
  {
    for(int i = 1; i<= n; i++)
      {
        v[cur] = i;
        func1(n, m, cur+1);
      }
  }
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i<m; i++)
    v.push_back(0);

  findSeq(n, m, 0);

  
}
