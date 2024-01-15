#include <bits/stdc++.h>
using namespace std;
int func1(int n, int k, vector<int> & coins)
{
  int result = 0;
  int value = k;
  for(int i = n-1; i>=0; i--)
    {
      result += (value/coins[i]);
      value %= coins[i];
      
    }
  return result;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

int n, k;
cin >> n >> k;

vector<int> coins(n);

for(int i = 0; i<n; i++)
  cin >> coins[i];

cout << func1(n, k, coins);
  
return 0;
}
