//BOJ 15649 N과 M(1)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  vector<int> v2(n);

  for(int i = 0; i<n; i++)
    {
      v[i] = i+1;
      v2[i] = (i<m)?0:1;
    }

  do
    {
      for(int i = 0; i<n; i++)
        {
          if(v2[i] == 0)
            cout << v[i] << " ";
        }
      cout << "\n";
      
    }while(next_permutation(v2.begin(), v2.end()));

  
}
