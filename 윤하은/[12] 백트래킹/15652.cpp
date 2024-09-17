//BOJ 15652 N과 M(4)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void func1(int n, int m, int cur)
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
    int before = (cur > 0) ? v[cur-1] : 1;
    for(int i = before; i<= n; i++)
      {
        v[cur] = i;
        func1(n, m, cur+1);
      }
  }
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i<m; i++)
    v.push_back(0);

  func1(n, m, 0);

  
}
