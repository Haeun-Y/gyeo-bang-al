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
/*
#include <bits/stdc++.h>
using namespace std;
int func1(int a, int b, int c)
{
  if(b==1) return a%c;
  else if(b%2 == 1) return ((a%c)*func1(a-1, b, c))%c;
  else
  {
    int num= func1(a, b/2, c);
    return (num * num)%c;
  }
  
}/*
long long func2(long long a, long long b, long long c)
{//a^b= (a^2)^b/2
  if(b == 0) return a%c;
  else if(b%2==1) return a;
  else return func2(a, b,c);
  
}*/
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  //a^b mod c
  int a, b, c;
  cin >> a >> b >> c;
  cout << func1(a, b, c);
}
*/
