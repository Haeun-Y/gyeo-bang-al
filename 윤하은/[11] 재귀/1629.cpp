//BOJ 1629 곱셈
#include <bits/stdc++.h>
using namespace std;
long long func1(long long a, long long b, long long c)
{
  //a^b mod c = (a^(b/2) mod c * a^(b/2) mod c) mod c
  if(b == 1) return a%c;
  else if(b%2 == 1)//b가 홀수
    return ((a%c) * func1(a, b-1, c))%c;

  else//b가 짝수
  {
    long long result = func1(a, b/2, c);
    return (result * result)%c;
  }

}
int main(void)
{
  
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;
  
  //a^b % c
  cout << func1(a, b, c);

}