#include <bits/stdc++.h>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int K; //명령의 수 
  cin >> K;
  
  stack<int> S;
  int num;
  
  while(K--){
      cin >> num;
      if(num == 0) S.pop();
      else S.push(num);
  }
  int sum = 0;
  
  while(!S.empty()){
      sum += S.top();
      S.pop();
  }
  cout << sum;
}