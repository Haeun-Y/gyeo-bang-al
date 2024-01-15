#include <bits/stdc++.h>
using namespace std;
int solution(int num)
{
  int answer =0;
  //1hr = 3600
  //1min = 60
  //1sec = 1

  answer += num/3600;
  num %= 3600;

  answer += num/60;
  num %= 60;

  answer += num;

  return answer;
}
int main() {

  int num;
  cin >> num;

  cout << solution(num);
    
}
