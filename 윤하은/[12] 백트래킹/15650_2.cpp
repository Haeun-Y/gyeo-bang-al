//BOJ 15650 N과 M(2)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  vector<int> v2(n);

  for(int i = 0; i<n; i++)
    {
      v[i] = i+1;
      if(i < m)
        v2[i] = 0;
      else v2[i] = 1;
    }
  
  //next_permutation 활용한 조합
  do
    {
      for(int i = 0; i<n; i++)
        {
          if(v2[i] == 0)
            cout << v[i] <<" ";
        }
      cout << "\n";
        
    }while(next_permutation(v2.begin(), v2.end()));
  
}
