#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void makeSequence(int n, int m, int cur)
{
  if(cur == m)//m개의 수로 이루어진 수열 완성
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
        makeSequence(n, m, cur+1);
      }
  }
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  v = vector<int>(m);

  makeSequence(n, m, 0);

  
}
