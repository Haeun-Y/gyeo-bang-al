#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}
int func1(vector<pair<int, int>> & v, int n)
{
  int result = 1;
  sort(v.begin(), v.end(), cmp);
  int cur = v[0].second;
  int i = 1;
  while(i < n)
    {
      if(v[i].first < cur)
      {
        i++;
        continue;
      }
      else
      {
        result++;
        cur = v[i].second;
        i++;
      }
    }
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> meetings(n);

  for(int i = 0; i<n; i++)
    cin >> meetings[i].first >> meetings[i].second;

  cout << func1(meetings, n);
    
}
