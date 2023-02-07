//BOJ 15649 N과 M(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<bool> isChecked;
void func(int cur, int n, int m)
{
  if(cur == m)
  {
    for(int i = 0; i<m; i++)
      cout << v[i] << " ";
    cout << "\n";
    return;
  }
  else
  {
    for(int i = 1; i<=n; i++)
      {
        if(!isChecked[i])
        {
          isChecked[i] = true;
          v[cur] = i;
          func(cur+1, n, m);
          isChecked[i] = false;
        }
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

  for(int i = 0; i<=n; i++)
    isChecked.push_back(false);

  func(0, n, m);
  
}
