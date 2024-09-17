//BOJ 10773 제로
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  stack<int> s;
  int k;
  cin >> k;
  for(int i =0; i<k; i++)
    {
      int num;
      cin >> num;
      if(num == 0)
        s.pop();
      else s.push(num);
      
    }
  int sum = 0;
  while(!s.empty())
    {
      sum += s.top();
      s.pop();
    }
  cout << sum;
    return 0;
}
