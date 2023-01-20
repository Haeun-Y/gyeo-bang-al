//BOJ 1629 곱셈
#include <bits/stdc++.h>
using namespace std;
long long calculate(long long a, long long b)
{
  if(b == 0)
    return 1;
  //a^b = (a^2)^b/2
  else
  {
    if(b%2==0)
      return calculate(a*a, b/2);
    else
      return (a * calculate(a, b-1));
  }
  
}
int main() {
  //a b c
  //a를 b번 곱한 수를 c로 나눈 나머지를 구하라
  // x-r = x/k*x/y
  // x%y = r
  // 
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int a,b,c;
  cin >> a >> b >> c;

  cout << calculate((long long)a, (long long)b)%c;

    
}
